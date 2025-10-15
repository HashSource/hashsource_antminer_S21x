# Bitmain Antminer S21 Hyd - Firmware Update Flow Analysis

- **Firmware Version**: FR-1.1 (250416-S21 Hyd.)
- **Base Path**: `/home/danielsokil/Lab/HashSource/hashsource_antminer_S21x/bitmain_firmware/FR-1.1(250416-S21 Hyd.)/minerfs.no_header.image_extract`

---

## Update Flow Overview

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                          USER UPLOADS .bmu FILE                             │
└────────────────────────────────────┬────────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────────┐
│ STEP 1: Web Interface (update.html)                                         │
│ Location: www/pages/update.html                                             │
│ Function: File upload form with "keep settings" checkbox                    │
│ POST to: /www/pages/cgi-bin/upgrade.cgi                                     │
└────────────────────────────────────┬────────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────────┐
│ STEP 2: CGI Upload Handler (upgrade.cgi)                                    │
│ Location: www/pages/cgi-bin/upgrade.cgi                                     │
│ Lines: 1-59                                                                 │
│                                                                             │
│ Actions:                                                                    │
│   • Parse multipart/form-data (lines 23-42)                                 │
│   • Save to /tmp/$$/update.bmu (line 8)                                     │
│   • Call: /usr/sbin/daemonc $file (line 44)                                 │
│   • Return JSON: {"stats":"success|error","code":"U00X","msg":"..."} (55)   │
│                                                                             │
│ Cleanup: rm -rf $file (line 14)                                             │
└────────────────────────────────────┬────────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────────┐
│ STEP 3: Update Daemon Client (daemonc)                                      │
│ Binary: usr/sbin/daemonc → usr/sbin/update-daemon                           │
│ Source: usr/sbin/update-daemon.c                                            │
│ Function: sub_10EB8 (lines 316-358)                                         │
│                                                                             │
│ Actions:                                                                    │
│   • Connect to 127.0.0.1:22322 (lines 329-345)                              │
│   • Send file path via socket (line 348)                                    │
│   • Receive status code (lines 350-357)                                     │
│   • Return: 0=success, other=error code                                     │
└────────────────────────────────────┬────────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────────┐
│ STEP 4: Update Daemon Server (daemons)                                      │
│ Binary: usr/sbin/daemons → usr/sbin/update-daemon                           │
│ Source: usr/sbin/update-daemon.c                                            │
│ Init: etc/init.d/S67update-daemon (started on boot)                         │
│                                                                             │
│ Server Function: main() with "daemons" arg (lines 100-143)                  │
│   • Bind to 127.0.0.1:22322 (lines 102-113)                                 │
│   • Listen for connections (line 119)                                       │
│   • Spawn thread per connection (line 137)                                  │
│                                                                             │
│ Thread Function: sub_10C8C (lines 237-314)                                  │
│   • Receive file path (line 254)                                            │
│   • Validate path characters [a-zA-Z0-9_.-] (lines 258-276)                 │
│   • Check file exists with access() (line 256)                              │
│   • Build command: "/usr/sbin/updateporc.sh <path>" (lines 277-279)         │
│   • Execute with system() (line 281)                                        │
│   • Return status code to client (lines 289-304)                            │
└────────────────────────────────────┬────────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────────┐
│ STEP 5: Update Processing Script (updateporc.sh)                            │
│ Location: usr/sbin/updateporc.sh                                            │
│ Lines: 1-333                                                                │
│                                                                             │
│ Initial Setup:                                                              │
│   • Get miner type: /www/pages/cgi-bin/miner_type.cgi (line 8)              │
│   • Check file header for update type (lines 17-30)                         │
│                                                                             │
│ ┌──────────────────────────────────────────────────────────────────────┐    │
│ │ TYPE DETECTION: checkType() - line 17                                │    │
│ │   header=$(head -c 20 "$FILE")                                       │    │
│ │   Look for: {type:pool} or {type:root} or {type:update}              │    │
│ └──────────────────────────────────────────────────────────────────────┘    │
│                                                                             │
│ Route to handler:                                                           │
│   • If {type:pool}   → poolUpdate() (lines 32-162)                          │
│   • If {type:root}   → rootUpdate() (lines 164-214)                         │
│   • Else (standard)  → FileParser validation (line 226)                     │
└────────────────────────────────────┬────────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────────┐
│ STEP 6: Firmware Package Validation (FileParser)                            │
│ Binary: usr/bin/FileParser                                                  │
│ Source: usr/bin/FileParser.c                                                │
│                                                                             │
│ Command: /usr/bin/FileParser -f "$subtype" $FILE /etc/bitmain.pub (line 226)│
│                                                                             │
│ Main Function: sub_12C40 (lines 792-1036)                                   │
│                                                                             │
│ ┌─────────────────────────────────────────────────────────────────────┐     │
│ │ VALIDATION SEQUENCE:                                                │     │
│ │                                                                     │     │
│ │ 1. Read 2048-byte header (line 839)                                 │     │
│ │                                                                     │     │
│ │ 2. Check magic byte == 0x26 (line 840)                              │     │
│ │    if ( *a4 == 38 )                                                 │     │
│ │                                                                     │     │
│ │ 3. Validate miner type hash (lines 842-847)                         │     │
│ │    v40 = sub_12180(miner_type, strlen(miner_type)) // CityHash64    │     │
│ │    memcpy(&dest, a4 + 2, 8)                                         │     │
│ │    if ( v40 == dest )  // Type hash must match                      │     │
│ │                                                                     │     │
│ │ 4. Validate content bitmap (lines 850-859)                          │     │
│ │    v39 = _byteswap_ushort(*(_WORD *)(a4 + 11))                      │     │
│ │    Count set bits, compare to file count                            │     │
│ │                                                                     │     │
│ │ 5. Verify file size matches header (lines 860-868)                  │     │
│ │    Calculate expected size, compare to actual                       │     │
│ │                                                                     │     │
│ │ 6. Load root public key (line 870)                                  │     │
│ │    fread(v25, 0x400u, 1u, v37) // /etc/bitmain.pub                  │     │
│ │                                                                     │     │
│ │ 7. Verify miner.pem signature (lines 877-884)                       │     │
│ │    sub_10C70(pem_data, pem_len, signature, root_pubkey)             │     │
│ │    → RSA_verify() with SHA256                                       │     │
│ │                                                                     │     │
│ │ 8. Extract component hashes (lines 917-923)                         │     │
│ │    For each file in bitmap:                                         │     │
│ │      sub_10DE8() → SHA256 hash of component                         │     │
│ │      Store hash + read signature (256 bytes each)                   │     │
│ │                                                                     │     │
│ │ 9. Verify master signature (lines 924-942)                          │     │
│ │    fseek(stream, -256, SEEK_END) // Last 256 bytes                  │     │
│ │    SHA256(all_component_hashes)                                     │     │
│ │    RSA_verify(hash, master_sig, miner.pem)                          │     │
│ │                                                                     │     │
│ │ 10. Success → Extract components to /tmp/tmpfw/ (if -s flag)        │     │
│ │                                                                     │     │
│ └─────────────────────────────────────────────────────────────────────┘     │
└────────────────────────────────────┬────────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────────┐
│ STEP 7: Version Check & Installation (updateporc.sh)                        │
│ Lines: 236-332                                                              │
│                                                                             │
│ Version Validation (lines 237-250):                                         │
│   version_fw=$(cat /usr/bin/fw_version)                                     │
│   version_isolate=$(cat /usr/bin/isolate_time)                              │
│   • Both must start with '2'                                                │
│   • version_fw > version_isolate (anti-downgrade)                           │
│                                                                             │
│ UBI Filesystem Setup:                                                       │
│   • prepare_ubifs() - Mount /dev/ubi1_0 to /tmp/updatedata (lines 265-309)  │
│   • Format if needed: ubiformat /dev/mtd6 (line 288)                        │
│                                                                             │
│ Installation:                                                               │
│   • Copy BMU: cp $FILE /tmp/updatedata/update.bmu (line 328)                │
│   • Sync filesystem (line 329)                                              │
│   • Unmount: umount /tmp/updatedata/ (line 330)                             │
│   • Set boot marker: flash_erase /dev/mtd0 0x1B00000 0x1 (line 331)         │
│                                                                             │
│ Result: System will apply update on next boot                               │
└─────────────────────────────────────────────────────────────────────────────┘
```

---

## Component Details

### 1. Web Interface

**File**: `www/pages/update.html`

```html
<!-- Form submits to upgrade.cgi -->
<form enctype="multipart/form-data">
    <input type="file" id="file">
    <span class="selfecheckbox checked" id="updateCheck"> <!-- Keep Settings -->
    <input type="button" id="updateFile">
</form>
<script src="/js/update.15d87e.js"></script>
```

**JavaScript Handler**: `www/pages/js/update.15d87e.js` (referenced but not analyzed)

---

### 2. CGI Upload Handler

**File**: `www/pages/cgi-bin/upgrade.cgi`

**Key Operations**:

```bash
# Line 7-8: Temporary file location
folder=/tmp/$$
file=$folder/update.bmu

# Line 18: Create temp directory
mkdir $folder

# Line 23-24: Parse HTTP headers
CR=`printf '\r'`
IFS=$CR

# Line 26-33: Skip HTTP headers until blank line
read -r start
while [ -n "$line" ]; do
    read -r line
done

# Line 37: Save uploaded file
cat - >> $file

# Line 39-42: Remove HTTP footer padding
fileNum=`cat $file | wc -m`
let fileNum=fileNum-$num
truncate -s $fileNum $file

# Line 44-45: Send to daemon
/usr/sbin/daemonc $file
err_flag=$?

# Line 55: Return JSON response
echo "{\"stats\":\"$stats\",\"code\":\"U00$err_flag\",\"msg\":\"$msg\"}"

# Line 57-59: Trigger miner restart on success
if [ $err_flag -eq 0 ]; then
    echo 2 > /tmp/miner_act
fi
```

**Error Codes**:

- `U000`: Success
- `U00X`: Error (X = return code from daemonc)

---

### 3. Update Daemon Binary

**Binary**: `usr/sbin/update-daemon` (both daemons and daemonc are symlinks)
**Source**: `usr/sbin/update-daemon.c`
**Header**: `usr/sbin/update-daemon.h`

#### Server Mode (daemons)

**Main Function**: `main()` lines 85-149

```c
// Detect mode by argv[0]
if ( strstr(*a2, "daemons") ) {
    v5 = socket(2, 1, 0);  // AF_INET, SOCK_STREAM

    // Bind to localhost:22322
    addr.sa_family = 2;  // AF_INET
    *(_DWORD *)&addr.sa_data[2] = inet_addr("127.0.0.1");
    *(_WORD *)addr.sa_data = sub_10C40("22322");  // Port conversion
    bind(v5, &addr, 0x10u);

    // Listen with backlog=512
    listen(v5, 512);

    // Accept loop
    do {
        arg = accept(v5, &v13, &addr_len);
        pthread_create(&newthread, 0, (void *(*)(void *))sub_10C8C, &arg);
    } while ( /* infinite */ );
}
```

**Thread Handler**: `sub_10C8C()` lines 237-314

```c
void __noreturn sub_10C8C(int *a1) {
    char command[1024];
    _DWORD buf[256];
    int v2 = *a1;  // Socket FD

    // Read file path from client
    read(v2, buf, 0x400u);
    printf("Recv:'%s'\r\n", (const char *)buf);

    // Check file exists
    if ( !access((const char *)buf, 0) ) {

        // SECURITY CHECK: Validate path characters
        // Lines 258-276
        v3 = LOBYTE(buf[0]);
        if ( LOBYTE(buf[0]) ) {
            v4 = *_ctype_b_loc();
            v5 = buf;
            do {
                // Allow: alphanumeric, underscore, hyphen, period
                if ( (v4[v3] & 8) == 0 && v3 != 95 && (unsigned int)(v3 - 45) > 2 ) {
                    puts("Invalid client content.");
                    close(v2);
                    pthread_exit(0);
                }
                v6 = *((unsigned __int8 *)v5 + 1);
                v5 = (_DWORD *)((char *)v5 + 1);
                v3 = v6;
            } while ( v6 );
        }

        // Build and execute command
        strcpy(command, "/usr/sbin/updateporc.sh ");
        strcpy(&command[24], (const char *)buf);
        v7 = system(command);  // POTENTIAL VULNERABILITY

        // Parse exit status and return to client
        if ( v7 == -1 ) {
            strcpy(v9, "500");
        } else if ( (v7 & 0x7F) != 0 ) {
            sprintf(v9, "6%d", BYTE1(v7));
        } else if ( BYTE1(v7) ) {
            sprintf(v9, "%d", BYTE1(v7));
        } else {
            strcpy(v9, "200");
        }

        v8 = strlen(v9);
        write(v2, v9, v8 + 1);
    } else {
        printf("File does not exist: %s\n", (const char *)buf);
    }

    close(v2);
    pthread_exit(0);
}
```

#### Client Mode (daemonc)

**Function**: `sub_10EB8()` lines 316-358

```c
int __fastcall sub_10EB8(const char *a1) {
    struct sockaddr v7;
    _DWORD buf[260];

    if ( !a1 )
        return -3;

    // Setup connection to localhost:22322
    v7.sa_family = 2;
    *(_DWORD *)&v7.sa_data[2] = inet_addr("127.0.0.1");
    *(_WORD *)v7.sa_data = sub_10C40("22322");

    v2 = socket(2, 1, 0);
    v3 = v2;
    if ( v2 < 0 ) {
        perror("socket err:");
        return -1;
    }

    if ( connect(v2, &v7, 0x10u) < 0 ) {
        perror("connect err:");
        return -2;
    }

    // Send file path
    v4 = strlen(a1);
    send(v3, a1, v4 + 1, 0);

    // Receive response
    memset(buf, 0, 1024);
    v5 = recv(v3, buf, 0x400u, 0);
    if ( v5 <= 0 )
        return -3;

    *((_BYTE *)buf + v5) = 0;
    result = sub_10C40((const char *)buf);  // Convert status to int
    if ( result == 200 )
        return 0;
    return result;
}
```

**Init Script**: `etc/init.d/S67update-daemon`

```bash
#!/bin/sh -e
function do_start() {
    /usr/sbin/daemons &
}

function do_stop() {
    exit 0
}

case "$1" in
    start|"")
        do_start
        ;;
    stop)
        do_stop
        ;;
esac
```

---

### 4. Update Processing Script

**File**: `usr/sbin/updateporc.sh`

#### Main Entry Point (lines 1-16)

```bash
#!/bin/sh
#$FILE: FileName
set -x
exec > /nvdata/update.log 2>&1

FILE=$1
if [ -f $FILE ];then
    type_result=`/www/pages/cgi-bin/miner_type.cgi`
    miner_type=`echo $type_result | jq ".miner_type" | sed 's/\"//g'`
    subtype=`echo $type_result | jq ".subtype" | sed 's/\"//g'`
else
    return 1
fi
```

#### Type Detection (lines 17-30)

```bash
function checkType(){
    header=$(head -c 20 "$FILE" 2>/dev/null)
    type_str=$(printf "$header" | grep -oE "\{[^}]*\}")
    type_length=0
    type="update"

    if echo "$type_str" | grep -q "{type:[^}]*}"; then
        type_length=${#type_str}
        type=$(echo $type_str | sed 's/.*{type:\(.*\)}.*/\1/')
        echo "The type is: $type"
    else
        echo "failed to get {type:*}, might be update file"
    fi
}
```

---

## Cryptographic Validation

### Public Keys

#### Root Key: `/etc/bitmain.pub`

```
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAz6xBmfPvBp8WV7ZksjUI
ureOSSANX7GFOwwxrRVSM7oLdQpxmlers01jSZNIA6x1AFKmMcSfLj3flK7axIVg
o25M47ujAOUkE6G3TSkckw7CX+LYH2ccc/BrIbry+Mf3UYPcklDSDRRtZrTnVRPS
SgF+UTVu0xNI1QAThtlGyfUtPfanmfu9d2YhYIXghbnbdOEm620pOleoU/9/wTnk
J68poRgbhNCDXfHeSjzl8UxM2ZY7iWbsdpQD7RWw/yfXyPYjw+9vEK323ByNapyN
P7eI4+4EeTYb3IFCjoQCz98paRbuDj4agdv+fGAPuhMa0x/JtchJ6cSQIs1ORXUb
XwIDAQAB
-----END PUBLIC KEY-----
```

**Key Type**: RSA-2048
**Used For**: Validating embedded miner.pem in firmware packages
**Location in Code**: FileParser.c:870

#### Advanced Key: `/etc/bitmain-adv.pub`

```
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4nK2btpK1JYkkB9t4Krs
NUuxTdGxABFkEP8dWAaf6F+wjZGi8EjVI3ISWEaijXQ0KdY1jP4ijyeEVNIP4mm+
Xt55rTQIuaV2r7U7tko8ZJqlRiS88Ls5ZFs6LYzeledAdL9IPQK4iNFah04JQU9t
P/cPsSZ62C7QhFEGT19DrKcjJ9HP8/424JRt+6suIjkiQPdeFkHoxTVwF+QGiQ04
uUbg2WS+aTVTyJv0pAMPxe1URo9ang3J4X75wOqJl4/9X+W/UDknz5g67zyBzBtU
/6RQQBzZWXgsMp70Gwc55kpUX9TfvEA0sdURD+fms8fVGbzOn23P/A8InVr7Vxbr
SQIDAQAB
-----END PUBLIC KEY-----
```

**Key Type**: RSA-2048
**Used For**: Validating pool and root update packages
**Location in Code**: updateporc.sh:44, 172

---

### Signature Verification Functions

#### Root Public Key Verification

**File**: `usr/bin/FileParser.c`
**Function**: `sub_10C70()` lines 241-289

```c
int __fastcall sub_10C70(int a1, int a2, int a3, int a4) {
    // a1 = pem data pointer
    // a2 = pem data length
    // a3 = signature pointer (256 bytes)
    // a4 = root public key data (bitmain.pub)

    _BYTE v14[112];  // SHA256 context
    _BYTE v15[32];   // SHA256 hash result
    int v16;         // Verify result
    int bio_RSA_PUBKEY;
    int v18;         // BIO object

    // Load root public key
    v18 = BIO_new_mem_buf(a4, 1024);
    bio_RSA_PUBKEY = PEM_read_bio_RSA_PUBKEY(v18, 0, 0, 0);

    if ( bio_RSA_PUBKEY ) {
        // Hash the PEM data
        SHA256_Init(v14);
        SHA256_Update(v14, a1, a2);
        SHA256_Final(v15, v14);

        // Verify signature
        v7 = RSA_verify(672, v15, 32, a3, 256, bio_RSA_PUBKEY);
        v16 = v7;

        // Cleanup
        if ( bio_RSA_PUBKEY )
            v7 = RSA_free(bio_RSA_PUBKEY);
        if ( v18 )
            v7 = BIO_free(v18);

        if ( v16 == 1 ) {
            return 0;  // Success
        } else {
            error = ERR_get_error(v7);
            v9 = (const char *)ERR_error_string(error, 0);
            printf("OpenSSL error: %s\n", v9);
            puts("Check miner.pem Failed!");
            return 13;
        }
    } else {
        v4 = ERR_get_error(0);
        v5 = (const char *)ERR_error_string(v4, 0);
        printf("OpenSSL error: %s\n", v5);
        puts("Read Root PubK Failed!");
        return 12;
    }
}
```

**Signature Algorithm**: RSA-2048 with SHA-256 (NID 672 = sha256WithRSAEncryption)

---

#### Component Hash Calculation

**File**: `usr/bin/FileParser.c`
**Function**: `sub_10DE8()` lines 301-414

```c
int __fastcall sub_10DE8(FILE *a1, int a2, _DWORD *a3, char a4, char a5, char a6) {
    // a1 = file stream
    // a2 = component size
    // a3 = output hash (32 bytes)
    // a4 = component type (0=BOOT, 1=DTB, 2=uImage, 3=minerfs, etc.)
    // a5 = is_signature (0=data, 1=signature)
    // a6 = should_extract (extract to /tmp/tmpfw/)

    _BYTE v26[16];  // SHA256 context
    size_t v27[256];  // Read buffer
    size_t n;
    FILE *s;
    int v30;

    memset(v27, 0, sizeof(v27));
    SHA256_Init(v26);
    v30 = 0;
    n = 0;
    s = 0;

    // Optionally create output file
    if ( a6 ) {
        strcpy(v17, "/tmp/tmpfw/");
        switch ( a4 ) {
            case 0: strcat(v17, "BOOT.bin"); break;
            case 1: strcat(v17, "devicetree.dtb"); break;
            case 2: strcat(v17, "uImage"); break;
            case 3: strcat(v17, "minerfs.image.gz"); break;
            case 4: strcat(v17, "update.image.gz"); break;
            case 5: strcat(v17, "crl.tar.gz"); break;
            case 6: strcat(v17, "miner.btm.tar.gz"); break;
            case 7: strcat(v17, "reserve"); break;
            case 9: strcat(v17, "datafile"); break;
        }
        if ( a5 )
            strcat(v17, ".sig");

        s = (FILE *)fopen64(v17, "wb");
    }

    // Read and hash in 1024-byte chunks
    while ( (unsigned int)(a2 - v30) > 0x400 ) {
        n = fread(v27, 1u, 0x400u, a1);
        v30 += n;
        SHA256_Update(v26, v27, 1024);
        if ( a6 && s )
            fwrite(v27, 1u, 0x400u, s);
    }

    // Read final chunk
    n = fread(v27, 1u, a2 - v30, a1);
    SHA256_Update(v26, v27, n);
    if ( a6 && s )
        fwrite(v27, 1u, n, s);

    // Finalize hash
    SHA256_Final(&v18, v26);

    if ( a6 && s ) {
        fclose(s);
        s = 0;
    }

    // Copy hash to output
    *a3 = v18;
    a3[1] = v19;
    a3[2] = v20;
    a3[3] = v21;
    a3[4] = v22;
    a3[5] = v23;
    a3[6] = v24;
    a3[7] = v25;

    return v25;
}
```

---

#### Pool/Root Package Verification

**File**: `usr/sbin/updateporc.sh`

**Pool Package** (lines 44-46):

```bash
openssl dgst -sha256 -verify /etc/bitmain-adv.pub -signature pool.json.sig pool.json
if [ $? -eq 0 ]; then
    echo "Verification pool.json successful."
```

**Root Package** (lines 172-174):

```bash
openssl dgst -sha256 -verify /etc/bitmain-adv.pub -signature root.json.sig root.json
if [ $? -eq 0 ]; then
    echo "Verification root.json successful."
```

---

## BMU File Format Specification

### Header Structure (2048 bytes)

```c
// Based on FileParser.c:sub_12C40 analysis

struct BMU_Header {
    uint8_t   magic;              // Offset 0:    Must be 0x26 (38)
    uint8_t   reserved1;          // Offset 1:    Reserved
    uint64_t  miner_type_hash;    // Offset 2:    CityHash64 of miner type string
    uint8_t   reserved2;          // Offset 10:   Reserved
    uint16_t  content_bitmap;     // Offset 11:   Big-endian bitmap of included files
    uint8_t   firmware_version[8];// Offset 13:   Firmware version string
    uint8_t   reserved3;          // Offset 21:   Reserved
    uint16_t  pem_length;         // Offset 22:   Big-endian PEM data length
    uint8_t   miner_pem[1024];    // Offset 24:   Embedded RSA public key (PEM format)
    uint8_t   pem_signature[256]; // Offset 1048: RSA signature of miner_pem (by bitmain.pub)
    uint8_t   file_count;         // Offset 1304: Number of component files
    uint32_t  unknown;            // Offset 1305: Unknown field (big-endian)

    // File descriptors (5 bytes each, up to 16 files max)
    struct {
        uint8_t   type;           // Offset 1309 + (i*5): File type ID
        uint32_t  size;           // Offset 1310 + (i*5): File size (big-endian)
    } files[16];                  // Max 16 files, total 80 bytes

    uint8_t   comment[256];       // Offset 1360: Package comment/description
    uint8_t   padding[432];       // Offset 1616: Padding to 2048 bytes
};
```

### File Type IDs

| ID  | Filename         | Description                  | Code Reference   |
| --- | ---------------- | ---------------------------- | ---------------- |
| 0   | BOOT.bin         | Bootloader                   | FileParser.c:337 |
| 1   | devicetree.dtb   | Device Tree Blob             | FileParser.c:340 |
| 2   | uImage           | Linux kernel                 | FileParser.c:343 |
| 3   | minerfs.image.gz | Root filesystem              | FileParser.c:346 |
| 4   | update.image.gz  | Update filesystem            | FileParser.c:349 |
| 5   | crl.tar.gz       | Certificate Revocation List  | FileParser.c:352 |
| 6   | miner.btm.tar.gz | Bitmain miner binary package | FileParser.c:355 |
| 7   | reserve          | Reserved                     | FileParser.c:358 |
| 9   | datafile         | Data file                    | FileParser.c:361 |

### Content Bitmap

16-bit bitmap (big-endian) indicating which components are present:

```
Bit 0:  BOOT.bin present
Bit 1:  devicetree.dtb present
Bit 2:  uImage present
Bit 3:  minerfs.image.gz present
Bit 4:  update.image.gz present
Bit 5:  crl.tar.gz present
Bit 6:  miner.btm.tar.gz present
Bit 7:  reserve present
Bit 8:  (unused)
Bit 9:  datafile present
Bit 10-15: (unused)
```

**Full Package Detection**: `if ( (v39 & 0xFE00) == 0xFE00 )` (FileParser.c:851)
This checks if bits 9-15 are all set, indicating a complete firmware package.

---

### File Layout

```
┌────────────────────────────────────────────────┐
│ BMU Header (2048 bytes)                        │
├────────────────────────────────────────────────┤
│ Component 0 Data (size from header)            │
├────────────────────────────────────────────────┤
│ Component 1 Data (size from header)            │
├────────────────────────────────────────────────┤
│ ...                                            │
├────────────────────────────────────────────────┤
│ Component N Data (size from header)            │
├────────────────────────────────────────────────┤
│ Component 0 Signature (256 bytes)              │
├────────────────────────────────────────────────┤
│ Component 1 Signature (256 bytes)              │
├────────────────────────────────────────────────┤
│ ...                                            │
├────────────────────────────────────────────────┤
│ Component N Signature (256 bytes)              │
├────────────────────────────────────────────────┤
│ Master Signature (256 bytes)                   │ ← Last 256 bytes of file
└────────────────────────────────────────────────┘
```

**Total Size Calculation** (FileParser.c:860):

```c
v46 = ((unsigned __int8)a4[1304] + 9) << 8;  // Header size
for ( j = 0; j < v48; ++j ) {
    v28 = _byteswap_ulong(*(_DWORD *)&a4[5 * j + 1310]);
    v46 += v28;  // Add component data size
}
// v46 should equal actual file size
```

---

### Miner Type Hash (CityHash64)

**File**: `usr/bin/FileParser.c`
**Function**: `sub_12180()` lines 640-788

**Purpose**: Prevents installing firmware for wrong miner model (e.g., S19 firmware on S21 device)

**Implementation**:

- Google's CityHash64 algorithm
- Hash of miner type string (e.g., "Antminer S21 Hyd")
- Stored at offset 2 in BMU header (8 bytes, little-endian)

**Validation** (FileParser.c:842-847):

```c
printf("miner_type %s\n", a2);
v8 = strlen(a2);
v40 = sub_12180((unsigned __int8 *)a2, v8);  // Calculate hash
memcpy(&dest, a4 + 2, sizeof(dest));          // Read from header
printf("miner_type_hash %16llx, bmu_hash %16llx\n", v40, dest);
if ( v40 == dest ) {
    // Type matches, continue validation
```

---

## Security Checkpoints

### Checkpoint 1: Web Upload

**Location**: `www/pages/update.html`

- **Check**: User authentication (handled by web server)
- **Threat**: Unauthorized firmware upload
- **Mitigation**: Web server authentication required

### Checkpoint 2: CGI Processing

**Location**: `www/pages/cgi-bin/upgrade.cgi:37-42`

- **Check**: HTTP multipart parsing
- **Threat**: Malformed upload could cause buffer overflow
- **Mitigation**: Fixed-size buffer with truncation

### Checkpoint 3: Daemon Connection

**Location**: `usr/sbin/update-daemon.c:329-345`

- **Check**: Localhost-only connection (127.0.0.1)
- **Threat**: Remote code execution
- **Mitigation**: Cannot be accessed from network

### Checkpoint 4: Path Validation

**Location**: `usr/sbin/update-daemon.c:258-276`

- **Check**: Alphanumeric + `_.-` characters only
- **Threat**: Path traversal, command injection
- **Mitigation**: Character whitelist (but weak - see Security Issues)
- **Code**:

```c
if ( (v4[v3] & 8) == 0 && v3 != 95 && (unsigned int)(v3 - 45) > 2 ) {
    puts("Invalid client content.");
    close(v2);
    pthread_exit(0);
}
```

### Checkpoint 5: File Existence

**Location**: `usr/sbin/update-daemon.c:256`

- **Check**: `access((const char *)buf, 0)`
- **Threat**: Processing non-existent files
- **Mitigation**: File must exist before processing

### Checkpoint 6: Update Type Detection

**Location**: `usr/sbin/updateporc.sh:17-30`

- **Check**: Parse first 20 bytes for `{type:X}` marker
- **Threat**: Wrong handler processing package
- **Mitigation**: Type-specific validation functions

### Checkpoint 7: Magic Byte Verification

**Location**: `usr/bin/FileParser.c:840`

- **Check**: First byte must be 0x26
- **Threat**: Non-BMU files being processed
- **Mitigation**: Immediate rejection if wrong magic
- **Code**:

```c
if ( *a4 == 38 )  // 0x26 in decimal
```

### Checkpoint 8: Miner Type Validation

**Location**: `usr/bin/FileParser.c:842-847`

- **Check**: CityHash64 of miner type string
- **Threat**: Installing incompatible firmware
- **Mitigation**: Type-specific hash prevents cross-model installation
- **Example**: S19 firmware cannot run on S21 hardware

### Checkpoint 9: Root Public Key Verification

**Location**: `usr/bin/FileParser.c:870-884`

- **Check**: RSA signature of embedded miner.pem
- **Threat**: Unauthorized package creation
- **Mitigation**: Only packages signed by Bitmain's private key accepted
- **Function**: `sub_10C70()` - RSA_verify with SHA256

### Checkpoint 10: File Size Validation

**Location**: `usr/bin/FileParser.c:868`

- **Check**: Calculated size vs actual file size
- **Threat**: Truncated or padded packages
- **Mitigation**: Exact size match required
- **Code**:

```c
if ( v46 == v42 ) {  // v46=expected, v42=actual
```

### Checkpoint 11: Component Hash Calculation

**Location**: `usr/bin/FileParser.c:917-923`

- **Check**: SHA256 hash of each component
- **Threat**: Tampered component files
- **Mitigation**: All components hashed before signature verification

### Checkpoint 12: Master Signature Verification

**Location**: `usr/bin/FileParser.c:937-942`

- **Check**: RSA signature of all component hashes
- **Threat**: Modified components after package creation
- **Mitigation**: Any modification invalidates signature
- **Code**:

```c
v30 = RSA_verify(672, v21, 32, v22, 256, bio_RSA_PUBKEY);
if ( v30 == 1 ) {
    // Success
```

### Checkpoint 13: Version Check

**Location**: `usr/sbin/updateporc.sh:237-250`

- **Check**: Version string validation and anti-downgrade
- **Threat**: Downgrade to vulnerable firmware
- **Mitigation**: Firmware version must be newer than isolation time
- **Code**:

```bash
if [[ ${version_fw:0:1} != "2" ]] || [[ ${version_isolate:0:1} != "2" ]]; then
    return 1
fi
if [ "$version_fw" -gt "$version_isolate" ]; then
    echo "Right firmware version\n"
else
    return 1
fi
```

### Checkpoint 14: Pool Package Validation

**Location**: `usr/sbin/updateporc.sh:44-46`

- **Check**: OpenSSL RSA signature with bitmain-adv.pub
- **Threat**: Malicious pool configuration
- **Mitigation**: Only signed pool configs accepted

### Checkpoint 15: Pool Timestamp Check

**Location**: `usr/sbin/updateporc.sh:99-102`

- **Check**: New timestamp > old timestamp
- **Threat**: Replay attacks with old pool configs
- **Mitigation**: Timestamp-based versioning prevents replay

### Checkpoint 16: Serial Number Validation

**Location**: `usr/sbin/updateporc.sh:105-130` (pool), `179-200` (root)

- **Check**: Device SN in package's allowed list
- **Threat**: Mass deployment of targeted attack
- **Mitigation**: Package can be limited to specific devices
- **Code**:

```bash
pool_sn=$(echo $json_data | jq -r '.sn')
local_sn=$(cat /config/sn)
echo "$pool_sn" | grep -q "$local_sn"
```

### Checkpoint 17: Root Package Validation

**Location**: `usr/sbin/updateporc.sh:172-174`

- **Check**: OpenSSL RSA signature with bitmain-adv.pub
- **Threat**: Unauthorized root access grant
- **Mitigation**: Only signed root packages accepted
- **Action**: Grants passwordless sudo to 'miner' user (line 203)

---

## Alternative Update Types

### Pool Configuration Update

**Trigger**: First 20 bytes contain `{type:pool}`

**Format**:

```
{type:pool}<header>pool.tar.gz
```

**Contents of pool.tar.gz**:

- `pool.json`: Pool configuration
- `pool.json.sig`: RSA signature of pool.json

**Validation Flow** (`updateporc.sh:32-162`):

1. Extract header to get type_length (line 39)
2. Extract pool.tar.gz starting after header: `tail -c +$((type_length + 1))` (line 39)
3. Decompress to /tmp/pool (lines 40-43)
4. Verify signature: `openssl dgst -sha256 -verify /etc/bitmain-adv.pub` (line 44)
5. Validate timestamp (line 99): `pool_time_old < pool_time_new`
6. Check serial number (lines 105-130): Device SN must be in allowed list
7. Check user ID consistency (line 96): New package must have same user ID
8. Update cgminer.conf (line 134):
   ```bash
   pools_data=$(jq '.pools' pool.json)
   jq --argjson pools "$pools_data" '.pools = $pools' /config/cgminer.conf
   ```
9. Reload cgminer (line 157): `cgminer-api {"command":"reload"}`

---

### Root Access Update

**Trigger**: First 20 bytes contain `{type:root}`

**Format**:

```
{type:root}<header>root.tar.gz
```

**Contents of root.tar.gz**:

- `root.json`: Root access configuration
- `root.json.sig`: RSA signature of root.json

**Validation Flow** (`updateporc.sh:164-214`):

1. Extract header to get type_length (line 166)
2. Extract root.tar.gz: `tail -c +$((type_length + 1))` (line 166)
3. Decompress to /tmp/root (lines 167-170)
4. Verify signature: `openssl dgst -sha256 -verify /etc/bitmain-adv.pub` (line 172)
5. Check serial number (lines 177-200): Device SN must be in allowed list
6. **GRANT ROOT ACCESS** (lines 203-205):
   ```bash
   echo 'miner ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
   chown root:root /usr/bin/sudo
   chmod 4755 /usr/bin/sudo
   ```

---

### Standard Firmware Update

**Trigger**: No `{type:X}` header, or `{type:update}`

**Validation**: Handled by FileParser binary

**Installation Flow** (`updateporc.sh:226-332`):

1. Call FileParser: `/usr/bin/FileParser -f "$subtype" $FILE /etc/bitmain.pub` (line 226)
2. Check version (lines 237-250):
   ```bash
   version_fw=$(cat /usr/bin/fw_version)
   version_isolate=$(cat /usr/bin/isolate_time)
   # Both must start with '2'
   # version_fw must be > version_isolate
   ```
3. Mount update partition (lines 254-326):
   - `ubiattach /dev/ubi_ctrl -m 6 -b 2` (line 267)
   - `mount -t ubifs /dev/ubi1_0 /tmp/updatedata` (line 255)
   - Format if needed (lines 287-307)
4. Copy BMU to update partition (line 328):
   ```bash
   rm -rf /tmp/updatedata/*
   cp $FILE /tmp/updatedata/update.bmu
   sync
   ```
5. Set boot marker (line 331):
   ```bash
   flash_erase /dev/mtd0 0x1B00000 0x1
   ```
6. On next boot, bootloader applies update from /tmp/updatedata/

---

## Key Files Reference

### Firmware Components

| Path                               | Description                  | Analysis Status |
| ---------------------------------- | ---------------------------- | --------------- |
| `www/pages/update.html`            | Web upload interface         | Analyzed        |
| `www/pages/cgi-bin/upgrade.cgi`    | Upload handler script        | Analyzed        |
| `www/pages/cgi-bin/miner_type.cgi` | Miner type detection         | Referenced      |
| `etc/init.d/S67update-daemon`      | Daemon startup script        | Analyzed        |
| `usr/sbin/update-daemon`           | Update daemon binary         | Decompiled      |
| `usr/sbin/update-daemon.c`         | Decompiled daemon source     | Analyzed        |
| `usr/sbin/update-daemon.h`         | Daemon header file           | Available       |
| `usr/sbin/daemonc`                 | Symlink to update-daemon     | Verified        |
| `usr/sbin/daemons`                 | Symlink to update-daemon     | Verified        |
| `usr/sbin/updateporc.sh`           | Update processing script     | Analyzed        |
| `usr/bin/FileParser`               | BMU validation binary        | Decompiled      |
| `usr/bin/FileParser.c`             | Decompiled FileParser source | Analyzed        |
| `usr/bin/FileParser.h`             | FileParser header file       | Available       |
| `etc/bitmain.pub`                  | Root RSA public key          | Extracted       |
| `etc/bitmain-adv.pub`              | Advanced features public key | Extracted       |

### Version Files

| Path                    | Description              | Purpose                                  |
| ----------------------- | ------------------------ | ---------------------------------------- |
| `/usr/bin/fw_version`   | Current firmware version | Anti-downgrade check (updateporc.sh:237) |
| `/usr/bin/isolate_time` | Isolation timestamp      | Anti-downgrade check (updateporc.sh:238) |
| `/config/sn`            | Device serial number     | SN validation (updateporc.sh:116, 186)   |

### Runtime Files

| Path                         | Description                   | Created By        |
| ---------------------------- | ----------------------------- | ----------------- |
| `/tmp/$$/update.bmu`         | Uploaded BMU file             | upgrade.cgi:8     |
| `/tmp/updatedata/update.bmu` | BMU staged for install        | updateporc.sh:328 |
| `/tmp/tmpfw/`                | Extracted firmware components | FileParser.c:332  |
| `/tmp/pool/`                 | Extracted pool config         | updateporc.sh:40  |
| `/tmp/root/`                 | Extracted root config         | updateporc.sh:167 |
| `/nvdata/update.log`         | Update process log            | updateporc.sh:4   |
| `/tmp/upgrade_result`        | Upgrade stderr output         | upgrade.cgi:21    |
| `/tmp/miner_act`             | Miner action trigger          | upgrade.cgi:58    |

### Filesystem Mounts

| Device        | Mount Point       | Type  | Purpose                     |
| ------------- | ----------------- | ----- | --------------------------- |
| `/dev/ubi1_0` | `/tmp/updatedata` | ubifs | Update staging area         |
| `/dev/mtd6`   | -                 | mtd   | Update partition (raw)      |
| `/dev/mtd0`   | -                 | mtd   | Boot partition (for marker) |

---

## Code Flow Summary

### Upload to Installation Timeline

```
T+0s    User clicks "Upload" in web interface
        ↓
T+1s    upgrade.cgi receives multipart data
        Creates /tmp/$$/update.bmu
        ↓
T+2s    upgrade.cgi calls daemonc with file path
        ↓
T+2s    daemonc connects to 127.0.0.1:22322
        ↓
T+2s    daemons accepts connection, spawns thread
        ↓
T+2s    Thread validates path characters
        ↓
T+3s    Thread executes: /usr/sbin/updateporc.sh /tmp/$$/update.bmu
        ↓
T+3s    updateporc.sh detects miner type
        ↓
T+3s    updateporc.sh checks for {type:X} header
        ↓
        ┌─────────────────┬──────────────────┬─────────────────┐
        │ {type:pool}     │ {type:root}      │ Standard        │
        ↓                 ↓                  ↓
T+4s    Extract pool.tar  Extract root.tar   Call FileParser
        Verify sig        Verify sig         ↓
        Check timestamp   Check SN           Verify magic 0x26
        Check SN          Grant sudo         ↓
        Update pools      ↓                  Verify type hash
        Reload miner      Return success     ↓
        ↓                                    Verify bitmain.pub sig
T+5s    Return success                       ↓
                                             Hash components
                                             ↓
                                             Verify master sig
                                             ↓
T+10s                                        Return success
                                             ↓
T+11s                                        Check version
                                             ↓
T+12s                                        Mount /tmp/updatedata
                                             ↓
T+13s                                        Copy BMU to partition
                                             ↓
T+14s                                        Set boot marker
                                             ↓
T+15s                                        Return success
        └─────────────────┴──────────────────┴─────────────────┘
                                             ↓
T+16s   daemonc returns status code to upgrade.cgi
        ↓
T+17s   upgrade.cgi returns JSON to web interface
        ↓
T+18s   upgrade.cgi sets miner action flag: echo 2 > /tmp/miner_act
        ↓
T+20s   Miner process restarts (if successful)
        ↓
BOOT    Bootloader detects marker at 0x1B00000
        ↓
BOOT    Applies update from /tmp/updatedata/update.bmu
        ↓
BOOT    Boots new firmware
```

---

## Cryptographic Chain of Trust

```
┌─────────────────────────────────────────────────────────────────┐
│                   Bitmain Private Key (Offline)                 │
│                   Type: RSA-2048                                │
│                   Protection: HSM/Secure Storage                │
└────────────────────────────────┬────────────────────────────────┘
                                 │ Signs
                                 ▼
┌─────────────────────────────────────────────────────────────────┐
│                   miner.pem (Embedded in BMU)                   │
│                   Type: RSA-2048 Public Key                     │
│                   Location: BMU Header offset 24-1047           │
│                   Signature: BMU Header offset 1048-1303        │
└────────────────────────────────┬────────────────────────────────┘
                                 │ Verified by
                                 ▼
┌─────────────────────────────────────────────────────────────────┐
│                   /etc/bitmain.pub (In Firmware)                │
│                   Type: RSA-2048 Public Key                     │
│                   Used: FileParser.c:870                        │
│                   Function: sub_10C70() - RSA_verify            │
└────────────────────────────────┬────────────────────────────────┘
                                 │ Enables
                                 ▼
┌─────────────────────────────────────────────────────────────────┐
│            miner.pem Validates Component Hashes                 │
│            Algorithm: SHA-256 + RSA-2048                        │
│            Function: FileParser.c:937                           │
└────────────────────────────────┬────────────────────────────────┘
                                 │ Protects
                                 ▼
┌─────────────────────────────────────────────────────────────────┐
│                     Individual Components                       │
│  • BOOT.bin           • devicetree.dtb    • uImage              │
│  • minerfs.image.gz   • update.image.gz   • crl.tar.gz          │
│  • miner.btm.tar.gz   • reserve           • datafile            │
└─────────────────────────────────────────────────────────────────┘
```

**Verification Steps**:

1. BMU contains miner.pem + signature
2. FileParser loads /etc/bitmain.pub
3. FileParser verifies: `RSA_verify(SHA256(miner.pem), signature, bitmain.pub)`
4. If valid, miner.pem is trusted
5. FileParser hashes each component: `SHA256(component_data)`
6. FileParser reads master signature (last 256 bytes of BMU)
7. FileParser verifies: `RSA_verify(SHA256(all_hashes), master_sig, miner.pem)`
8. If valid, all components are authentic

**Security Properties**:

- Two-tier PKI: Root key → Package key
- Package key can be rotated without firmware update
- Any modification to header or components invalidates signature
- Cryptographically impossible to forge without private keys

---

## Tools for Analysis

### Extract BMU Header

```bash
head -c 2048 firmware.bmu > header.bin
hexdump -C header.bin
```

### Verify Magic Byte

```bash
head -c 1 firmware.bmu | od -An -tx1
# Should output: 26
```

### Extract Miner Type Hash

```bash
dd if=firmware.bmu bs=1 skip=2 count=8 2>/dev/null | od -An -tx8
```

### Extract Content Bitmap

```bash
dd if=firmware.bmu bs=1 skip=11 count=2 2>/dev/null | od -An -tx2
```

### Extract Firmware Version

```bash
dd if=firmware.bmu bs=1 skip=13 count=8 2>/dev/null
```

### Extract miner.pem

```bash
dd if=firmware.bmu bs=1 skip=24 count=1024 2>/dev/null > miner.pem
```

### Extract miner.pem Signature

```bash
dd if=firmware.bmu bs=1 skip=1048 count=256 2>/dev/null > miner.pem.sig
```

### Verify miner.pem Signature

```bash
# Extract PEM and signature
dd if=firmware.bmu bs=1 skip=24 count=1024 2>/dev/null > miner.pem
dd if=firmware.bmu bs=1 skip=1048 count=256 2>/dev/null > miner.pem.sig

# Verify with root public key
openssl dgst -sha256 -verify /etc/bitmain.pub -signature miner.pem.sig miner.pem
```

---

## Related Documentation

- Bitmain S21 Hyd Technical Manual
- OpenSSL RSA_verify Documentation
- UBI Filesystem Specification
- CityHash64 Algorithm Reference

---
