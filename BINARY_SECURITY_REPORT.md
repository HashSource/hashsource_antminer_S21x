# ELF Binary Security Analysis

**Generated:** Wed Oct 15 04:14:39 PM EDT 2025
**Firmware:** FR-1.1(250416-S21 Hyd.)
**Tool:** [binary-security-check](https://codeberg.org/koutheir/binary-security-check)

The status of the security feature in the binary is indicated by a letter before the keyword:

- `+` means the feature is present/supported.
- `!` means the feature is absent/unsupported.
- `~` means the feature is probably present/supported.
- `?` means the feature status is unknown.

## For example, `!ASLR` means the binary does not support Address Space Layout Randomization.

## `bin/busybox`

```
bin/busybox: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!readlink,!getcwd,!fprintf,!vprintf,!memcpy,!memset,!read,!vsprintf,!strncpy,!printf,!snprintf,!getlogin_r,!dprintf,!strcpy,!realpath,!vfprintf,!getgroups,!fread,!ttyname_r,!poll,!memmove,!longjmp,!vsnprintf,!fgets_unlocked,!stpcpy,!recvfrom,!sprintf,!vasprintf,!strcat,!syslog)
```

## `lib/debug/libstdc++.so.6.0.24`

```
lib/debug/libstdc++.so.6.0.24: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!mbsnrtowcs,!poll,!fprintf,!wmemset,!wmemmove,!wmemcpy,!memmove,!memcpy,!mbsrtowcs,!vsnprintf,!wcrtomb,!wcsnrtombs,!fread,!read,!sprintf,!memset)
```

## `lib/ld-2.25.so`

```

```

## `lib/libanl-2.25.so`

```
lib/libanl-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `lib/libatomic.so.1.2.0`

```
lib/libatomic.so.1.2.0: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `lib/libc-2.25.so`

```

```

## `lib/libcrypt-2.25.so`

```
lib/libcrypt-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+explicit_bzero,!memcpy,!memset,!fread,!strncpy)
```

## `lib/libdl-2.25.so`

```
lib/libdl-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strcpy)
```

## `lib/libgcc_s.so.1`

```
lib/libgcc_s.so.1: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!memset)
```

## `lib/libm-2.25.so`

```
lib/libm-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset)
```

## `lib/libnsl-2.25.so`

```
lib/libnsl-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!gethostname,!memcpy,!memset,!strncpy,!asprintf,!syslog,!pread,!strcpy,!fprintf,!getdomainname,!snprintf,!memmove,!printf)
```

## `lib/libnss_dns-2.25.so`

```
lib/libnss_dns-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!sprintf,!memcpy)
```

## `lib/libnss_files-2.25.so`

```
lib/libnss_files-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!strcpy,!fgets_unlocked,!strncpy)
```

## `lib/libpthread-2.25.so`

```
lib/libpthread-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!memset,!sprintf)
```

## `lib/libresolv-2.25.so`

```
lib/libresolv-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fprintf,!sprintf,!read,!memcpy,!strcpy,!fgets,!memset,!snprintf,!memmove,!recvfrom,!strncpy)
```

## `lib/librt-2.25.so`

```
lib/librt-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!memset,!memcpy)
```

## `lib/libstdc++.so.6.0.24`

```
lib/libstdc++.so.6.0.24: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!wcsnrtombs,!mbsrtowcs,!memmove,!memcpy,!fread,!wmemset,!fprintf,!poll,!vsnprintf,!wmemmove,!wcrtomb,!mbsnrtowcs,!memset,!wmemcpy,!sprintf)
```

## `lib/libutil-2.25.so`

```
lib/libutil-2.25.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!ptsname_r,!memset,!strncpy,!memcpy,!strcpy,!ttyname_r)
```

## `sbin/halt`

```
sbin/halt: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+snprintf,+fprintf,!memset,!readlink,!fgets,!memcpy,!strncpy)
```

## `sbin/id2mac`

```
sbin/id2mac: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!sprintf,!fread)
```

## `sbin/init`

```
sbin/init: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+strcpy,+fdelt,+sprintf,+strncat,+fprintf,+syslog,+vsnprintf,+strncpy,+snprintf,!read,!fgets,!memset,!memcpy,!strncpy,!fread)
```

## `sbin/killall5`

```
sbin/killall5: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+vfprintf,+fprintf,+printf,+snprintf,+memcpy,+vsyslog,!strcpy,!readlink,!memcpy,!memmove,!fread,!memset)
```

## `sbin/shutdown`

```
sbin/shutdown: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+fprintf,+strncat,+sprintf,+syslog,+strcat,+longjmp,+memcpy,+snprintf,!fgets,!gethostname,!memcpy,!memset,!strncpy)
```

## `usr/bin/bmminer`

```
usr/bin/bmminer: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fprintf,!read,!fgets,!snprintf,!strncat,!memset,!strcat,!strncpy,!sprintf,!printf,!syslog,!fread,!stpcpy,!strcpy,!memcpy,!vfprintf,!memmove,!gethostname,!vsnprintf,!recv)
```

## `usr/bin/cgminer`

```
usr/bin/cgminer: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!recv,!vsnprintf,!strncpy,!read,!vfprintf,!memcpy,!syslog,!fprintf,!printf,!strcpy,!memset,!fgets,!strcat,!sprintf,!stpcpy,!fread,!snprintf,!strncat,!memmove)
```

## `usr/bin/cgminer-api`

```
usr/bin/cgminer-api: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!recv,!printf,!fprintf)
```

## `usr/bin/cvtsudoers`

```
usr/bin/cvtsudoers: !ASLR +STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+printf,+memcpy,+fprintf,+vfprintf,!getdomainname,!read,!memset,!fread,!memcpy)
```

## `usr/bin/FileParser`

```
usr/bin/FileParser: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!fread,!memcpy,!printf,!strcpy)
```

## `usr/bin/jq`

```
usr/bin/jq: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fprintf,!fgets,!printf,!memset,!strncpy,!realpath,!memmove,!snprintf,!memcpy,!fread,!vsnprintf,!strcpy)
```

## `usr/bin/kmod`

```
usr/bin/kmod: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!strcpy,!snprintf,!vfprintf,!vasprintf,!sprintf,!memcpy,!asprintf,!printf,!fgets,!memmove,!fread,!fprintf,!syslog,!memset)
```

## `usr/bin/monitor-ipsig`

```
usr/bin/monitor-ipsig: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!memcpy,!memset,!stpcpy,!sprintf,!strcpy,!strcat,!recvfrom,!strncpy)
```

## `usr/bin/monitor-recobtn`

```
usr/bin/monitor-recobtn: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!sprintf,!printf)
```

## `usr/bin/netcat`

```
usr/bin/netcat: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!memmove,!memcpy,!snprintf,!memset,!sprintf,!recvfrom,!strncpy,!vsnprintf,!read,!fgets,!fprintf)
```

## `usr/bin/ntpdate`

```
usr/bin/ntpdate: +ASLR +STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC +IMMEDIATE-BIND ~FORTIFY-SOURCE(+vfprintf,+syslog,+fprintf,+printf,+memcpy,+poll,!fgets,!read,!memcpy,!memmove,!fread,!memset,!getcwd,!recvfrom)
```

## `usr/bin/openssl`

```
usr/bin/openssl: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!fprintf,!memset,!readlink,!vsnprintf,!strcpy,!memcpy,!fgets,!stpcpy,!syslog,!printf,!strncpy,!sprintf)
```

## `usr/bin/pcregrep`

```
usr/bin/pcregrep: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!sprintf,!fread,!fgets,!fprintf,!memmove,!snprintf)
```

## `usr/bin/pcretest`

```
usr/bin/pcretest: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fread,!printf,!sprintf,!memcpy,!fgets,!memmove,!strcpy,!fprintf)
```

## `usr/bin/sudo`

```
usr/bin/sudo: !ASLR +STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+vfprintf,+printf,+strncpy,!memcpy,!getcwd,!strncpy,!read,!getgroups,!recv,!memset)
```

## `usr/bin/sudoreplay`

```
usr/bin/sudoreplay: !ASLR +STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+printf,+memcpy,+fprintf,!read)
```

## `usr/bin/xmlwf`

```
usr/bin/xmlwf: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strcpy,!memcpy,!fprintf,!read)
```

## `usr/libexec/sudo/libsudo_util.so.0.0.0`

```
usr/libexec/sudo/libsudo_util.so.0.0.0: +ASLR +STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+memcpy,+vfprintf,!memcpy,!memset,!read,!gethostname,!ppoll,!memmove)
```

## `usr/lib/libavahi-common.so.3.5.3`

```
usr/lib/libavahi-common.so.3.5.3: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strncpy,!vsnprintf,!memcpy,!snprintf,!read,!memset,!poll)
```

## `usr/lib/libavahi-core.so.7.0.2`

```
usr/lib/libavahi-core.so.7.0.2: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fgets,!gethostname,!memcpy,!fprintf,!printf,!snprintf,!sprintf,!memset,!vsnprintf)
```

## `usr/lib/libcrypto.so.1.1`

```
usr/lib/libcrypto.so.1.1: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strcat,!strncpy,!stpcpy,!recvfrom,!fgets,!fprintf,!sprintf,!memcpy,!syslog,!fread,!memset,!memmove,!strcpy,!vfprintf,!read)
```

## `usr/lib/libdaemon.so.0.5.0`

```
usr/lib/libdaemon.so.0.5.0: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!vfprintf,!memcpy,!read,!asprintf,!vsyslog,!snprintf)
```

## `usr/lib/libevent-2.1.so.6.0.2`

```
usr/lib/libevent-2.1.so.6.0.2: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!vsnprintf,!memset,!memcpy,!gethostname,!poll,!fprintf,!recvfrom,!memmove)
```

## `usr/lib/libevent_core-2.1.so.6.0.2`

```
usr/lib/libevent_core-2.1.so.6.0.2: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!memmove,!vsnprintf,!fprintf,!memset,!read,!poll)
```

## `usr/lib/libevent_extra-2.1.so.6.0.2`

```
usr/lib/libevent_extra-2.1.so.6.0.2: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!recvfrom,!memset,!gethostname,!memcpy)
```

## `usr/lib/libevent_openssl-2.1.so.6.0.2`

```
usr/lib/libevent_openssl-2.1.so.6.0.2: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/libevent_pthreads-2.1.so.6.0.2`

```
usr/lib/libevent_pthreads-2.1.so.6.0.2: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/libexpat.so.1.6.10`

```
usr/lib/libexpat.so.1.6.10: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memmove,!memset,!read,!memcpy,!fprintf)
```

## `usr/lib/libip4tc.so.2.0.0`

```
usr/lib/libip4tc.so.2.0.0: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!fprintf,!strncpy,!strcpy,!memcpy,!memset)
```

## `usr/lib/libip6tc.so.2.0.0`

```
usr/lib/libip6tc.so.2.0.0: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strncpy,!printf,!memcpy,!fprintf,!strcpy,!memset)
```

## `usr/lib/libiptc.so.0.0.0`

```
usr/lib/libiptc.so.0.0.0: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/libkmod.so.2.3.3`

```
usr/lib/libkmod.so.2.3.3: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memmove,!fread,!snprintf,!asprintf,!vfprintf,!read,!sprintf,!fprintf,!fgets,!memcpy,!memset)
```

## `usr/lib/libpcrecpp.so.0.0.1`

```
usr/lib/libpcrecpp.so.0.0.1: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!memcpy)
```

## `usr/lib/libpcreposix.so.0.0.6`

```
usr/lib/libpcreposix.so.0.0.6: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strncpy,!sprintf)
```

## `usr/lib/libpcre.so.1.2.10`

```
usr/lib/libpcre.so.1.2.10: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!memcpy,!memmove)
```

## `usr/lib/libssl.so.1.1`

```
usr/lib/libssl.so.1.1: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!sprintf,!memmove,!memset,!strcpy,!memcpy)
```

## `usr/lib/libxtables.so.12.2.0`

```
usr/lib/libxtables.so.12.2.0: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!fprintf,!strcat,!vfprintf,!sprintf,!fgets,!strcpy,!memcpy,!printf,!snprintf,!memset,!strncpy,!vsnprintf)
```

## `usr/lib/libz.so.1.2.11`

```
usr/lib/libz.so.1.2.11: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!snprintf,!memset,!memcpy,!vsnprintf,!read)
```

## `usr/lib/lighttpd/mod_accesslog.so`

```
usr/lib/lighttpd/mod_accesslog.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!syslog)
```

## `usr/lib/lighttpd/mod_access.so`

```
usr/lib/lighttpd/mod_access.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_alias.so`

```
usr/lib/lighttpd/mod_alias.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_auth.so`

```
usr/lib/lighttpd/mod_auth.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!fprintf,!strncat,!strncpy)
```

## `usr/lib/lighttpd/mod_cgi.so`

```
usr/lib/lighttpd/mod_cgi.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!fprintf,!memcpy)
```

## `usr/lib/lighttpd/mod_cml.so`

```
usr/lib/lighttpd/mod_cml.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/lighttpd/mod_compress.so`

```
usr/lib/lighttpd/mod_compress.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!read)
```

## `usr/lib/lighttpd/mod_dirlisting.so`

```
usr/lib/lighttpd/mod_dirlisting.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strcpy,!memcpy,!fprintf)
```

## `usr/lib/lighttpd/mod_evasive.so`

```
usr/lib/lighttpd/mod_evasive.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_evhost.so`

```
usr/lib/lighttpd/mod_evhost.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_expire.so`

```
usr/lib/lighttpd/mod_expire.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_extforward.so`

```
usr/lib/lighttpd/mod_extforward.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/lighttpd/mod_fastcgi.so`

```
usr/lib/lighttpd/mod_fastcgi.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!stpcpy,!memcpy,!read)
```

## `usr/lib/lighttpd/mod_flv_streaming.so`

```
usr/lib/lighttpd/mod_flv_streaming.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_indexfile.so`

```
usr/lib/lighttpd/mod_indexfile.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_magnet.so`

```
usr/lib/lighttpd/mod_magnet.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_mysql_vhost.so`

```
usr/lib/lighttpd/mod_mysql_vhost.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_proxy.so`

```
usr/lib/lighttpd/mod_proxy.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read)
```

## `usr/lib/lighttpd/mod_redirect.so`

```
usr/lib/lighttpd/mod_redirect.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_rewrite.so`

```
usr/lib/lighttpd/mod_rewrite.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/lighttpd/mod_rrdtool.so`

```
usr/lib/lighttpd/mod_rrdtool.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fprintf,!read)
```

## `usr/lib/lighttpd/mod_scgi.so`

```
usr/lib/lighttpd/mod_scgi.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!stpcpy,!read,!memcpy)
```

## `usr/lib/lighttpd/mod_secdownload.so`

```
usr/lib/lighttpd/mod_secdownload.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/lighttpd/mod_setenv.so`

```
usr/lib/lighttpd/mod_setenv.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/lighttpd/mod_simple_vhost.so`

```
usr/lib/lighttpd/mod_simple_vhost.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/lighttpd/mod_ssi.so`

```
usr/lib/lighttpd/mod_ssi.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!fprintf,!read)
```

## `usr/lib/lighttpd/mod_staticfile.so`

```
usr/lib/lighttpd/mod_staticfile.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fprintf)
```

## `usr/lib/lighttpd/mod_status.so`

```
usr/lib/lighttpd/mod_status.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!sprintf,!snprintf)
```

## `usr/lib/lighttpd/mod_trigger_b4_dl.so`

```
usr/lib/lighttpd/mod_trigger_b4_dl.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/lighttpd/mod_userdir.so`

```
usr/lib/lighttpd/mod_userdir.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/lighttpd/mod_usertrack.so`

```
usr/lib/lighttpd/mod_usertrack.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/lighttpd/mod_webdav.so`

```
usr/lib/lighttpd/mod_webdav.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy)
```

## `usr/lib/xtables/libip6t_ah.so`

```
usr/lib/xtables/libip6t_ah.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_DNAT.so`

```
usr/lib/xtables/libip6t_DNAT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!printf)
```

## `usr/lib/xtables/libip6t_DNPT.so`

```
usr/lib/xtables/libip6t_DNPT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_dst.so`

```
usr/lib/xtables/libip6t_dst.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_eui64.so`

```
usr/lib/xtables/libip6t_eui64.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/xtables/libip6t_frag.so`

```
usr/lib/xtables/libip6t_frag.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_hbh.so`

```
usr/lib/xtables/libip6t_hbh.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_hl.so`

```
usr/lib/xtables/libip6t_hl.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_HL.so`

```
usr/lib/xtables/libip6t_HL.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_icmp6.so`

```
usr/lib/xtables/libip6t_icmp6.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!memcpy)
```

## `usr/lib/xtables/libip6t_ipv6header.so`

```
usr/lib/xtables/libip6t_ipv6header.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_LOG.so`

```
usr/lib/xtables/libip6t_LOG.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_MASQUERADE.so`

```
usr/lib/xtables/libip6t_MASQUERADE.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_mh.so`

```
usr/lib/xtables/libip6t_mh.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_NETMAP.so`

```
usr/lib/xtables/libip6t_NETMAP.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_REDIRECT.so`

```
usr/lib/xtables/libip6t_REDIRECT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_REJECT.so`

```
usr/lib/xtables/libip6t_REJECT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_rt.so`

```
usr/lib/xtables/libip6t_rt.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_SNAT.so`

```
usr/lib/xtables/libip6t_SNAT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_SNPT.so`

```
usr/lib/xtables/libip6t_SNPT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libip6t_srh.so`

```
usr/lib/xtables/libip6t_srh.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_ah.so`

```
usr/lib/xtables/libipt_ah.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_CLUSTERIP.so`

```
usr/lib/xtables/libipt_CLUSTERIP.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!sprintf)
```

## `usr/lib/xtables/libipt_DNAT.so`

```
usr/lib/xtables/libipt_DNAT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_ECN.so`

```
usr/lib/xtables/libipt_ECN.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_icmp.so`

```
usr/lib/xtables/libipt_icmp.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!printf)
```

## `usr/lib/xtables/libipt_LOG.so`

```
usr/lib/xtables/libipt_LOG.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_MASQUERADE.so`

```
usr/lib/xtables/libipt_MASQUERADE.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_NETMAP.so`

```
usr/lib/xtables/libipt_NETMAP.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_realm.so`

```
usr/lib/xtables/libipt_realm.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!fprintf)
```

## `usr/lib/xtables/libipt_REDIRECT.so`

```
usr/lib/xtables/libipt_REDIRECT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_REJECT.so`

```
usr/lib/xtables/libipt_REJECT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_SNAT.so`

```
usr/lib/xtables/libipt_SNAT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_ttl.so`

```
usr/lib/xtables/libipt_ttl.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_TTL.so`

```
usr/lib/xtables/libipt_TTL.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libipt_ULOG.so`

```
usr/lib/xtables/libipt_ULOG.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_addrtype.so`

```
usr/lib/xtables/libxt_addrtype.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_AUDIT.so`

```
usr/lib/xtables/libxt_AUDIT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_bpf.so`

```
usr/lib/xtables/libxt_bpf.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!printf)
```

## `usr/lib/xtables/libxt_cgroup.so`

```
usr/lib/xtables/libxt_cgroup.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_CHECKSUM.so`

```
usr/lib/xtables/libxt_CHECKSUM.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_CLASSIFY.so`

```
usr/lib/xtables/libxt_CLASSIFY.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_cluster.so`

```
usr/lib/xtables/libxt_cluster.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_comment.so`

```
usr/lib/xtables/libxt_comment.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!snprintf)
```

## `usr/lib/xtables/libxt_connbytes.so`

```
usr/lib/xtables/libxt_connbytes.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_connlimit.so`

```
usr/lib/xtables/libxt_connlimit.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_connmark.so`

```
usr/lib/xtables/libxt_connmark.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_CONNMARK.so`

```
usr/lib/xtables/libxt_CONNMARK.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_CONNSECMARK.so`

```
usr/lib/xtables/libxt_CONNSECMARK.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_conntrack.so`

```
usr/lib/xtables/libxt_conntrack.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!memset,!printf)
```

## `usr/lib/xtables/libxt_cpu.so`

```
usr/lib/xtables/libxt_cpu.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_CT.so`

```
usr/lib/xtables/libxt_CT.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!printf)
```

## `usr/lib/xtables/libxt_dccp.so`

```
usr/lib/xtables/libxt_dccp.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_devgroup.so`

```
usr/lib/xtables/libxt_devgroup.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fprintf,!printf)
```

## `usr/lib/xtables/libxt_dscp.so`

```
usr/lib/xtables/libxt_dscp.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_DSCP.so`

```
usr/lib/xtables/libxt_DSCP.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_ecn.so`

```
usr/lib/xtables/libxt_ecn.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_esp.so`

```
usr/lib/xtables/libxt_esp.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_hashlimit.so`

```
usr/lib/xtables/libxt_hashlimit.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_helper.so`

```
usr/lib/xtables/libxt_helper.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_HMARK.so`

```
usr/lib/xtables/libxt_HMARK.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_IDLETIMER.so`

```
usr/lib/xtables/libxt_IDLETIMER.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_ipcomp.so`

```
usr/lib/xtables/libxt_ipcomp.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_iprange.so`

```
usr/lib/xtables/libxt_iprange.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!memset,!fprintf)
```

## `usr/lib/xtables/libxt_ipvs.so`

```
usr/lib/xtables/libxt_ipvs.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_LED.so`

```
usr/lib/xtables/libxt_LED.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!snprintf)
```

## `usr/lib/xtables/libxt_length.so`

```
usr/lib/xtables/libxt_length.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_limit.so`

```
usr/lib/xtables/libxt_limit.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_mac.so`

```
usr/lib/xtables/libxt_mac.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_mark.so`

```
usr/lib/xtables/libxt_mark.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_MARK.so`

```
usr/lib/xtables/libxt_MARK.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_multiport.so`

```
usr/lib/xtables/libxt_multiport.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_nfacct.so`

```
usr/lib/xtables/libxt_nfacct.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_NFLOG.so`

```
usr/lib/xtables/libxt_NFLOG.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_NFQUEUE.so`

```
usr/lib/xtables/libxt_NFQUEUE.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_osf.so`

```
usr/lib/xtables/libxt_osf.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_owner.so`

```
usr/lib/xtables/libxt_owner.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_physdev.so`

```
usr/lib/xtables/libxt_physdev.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_pkttype.so`

```
usr/lib/xtables/libxt_pkttype.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_policy.so`

```
usr/lib/xtables/libxt_policy.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_quota.so`

```
usr/lib/xtables/libxt_quota.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_rateest.so`

```
usr/lib/xtables/libxt_rateest.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!strncpy)
```

## `usr/lib/xtables/libxt_RATEEST.so`

```
usr/lib/xtables/libxt_RATEEST.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_recent.so`

```
usr/lib/xtables/libxt_recent.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strncpy,!printf)
```

## `usr/lib/xtables/libxt_rpfilter.so`

```
usr/lib/xtables/libxt_rpfilter.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_sctp.so`

```
usr/lib/xtables/libxt_sctp.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!printf)
```

## `usr/lib/xtables/libxt_SECMARK.so`

```
usr/lib/xtables/libxt_SECMARK.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_set.so`

```
usr/lib/xtables/libxt_set.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!memset,!strncpy)
```

## `usr/lib/xtables/libxt_SET.so`

```
usr/lib/xtables/libxt_SET.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!memset,!strncpy)
```

## `usr/lib/xtables/libxt_socket.so`

```
usr/lib/xtables/libxt_socket.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_standard.so`

```
usr/lib/xtables/libxt_standard.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/xtables/libxt_statistic.so`

```
usr/lib/xtables/libxt_statistic.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_string.so`

```
usr/lib/xtables/libxt_string.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!strncpy,!printf)
```

## `usr/lib/xtables/libxt_SYNPROXY.so`

```
usr/lib/xtables/libxt_SYNPROXY.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_tcpmss.so`

```
usr/lib/xtables/libxt_tcpmss.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_TCPMSS.so`

```
usr/lib/xtables/libxt_TCPMSS.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_TCPOPTSTRIP.so`

```
usr/lib/xtables/libxt_TCPOPTSTRIP.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_tcp.so`

```
usr/lib/xtables/libxt_tcp.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_TEE.so`

```
usr/lib/xtables/libxt_TEE.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_time.so`

```
usr/lib/xtables/libxt_time.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!snprintf,!printf)
```

## `usr/lib/xtables/libxt_tos.so`

```
usr/lib/xtables/libxt_tos.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_TOS.so`

```
usr/lib/xtables/libxt_TOS.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_TPROXY.so`

```
usr/lib/xtables/libxt_TPROXY.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_TRACE.so`

```
usr/lib/xtables/libxt_TRACE.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/lib/xtables/libxt_u32.so`

```
usr/lib/xtables/libxt_u32.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/lib/xtables/libxt_udp.so`

```
usr/lib/xtables/libxt_udp.so: +ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf)
```

## `usr/sbin/antlogin`

```
usr/sbin/antlogin: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ?FORTIFY-SOURCE()
```

## `usr/sbin/avahi-autoipd`

```
usr/sbin/avahi-autoipd: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!vsnprintf,!read,!memcpy,!printf,!fread,!poll,!memset,!fprintf,!recvfrom)
```

## `usr/sbin/avahi-daemon`

```
usr/sbin/avahi-daemon: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!memmove,!vsnprintf,!fprintf,!memset,!read,!strncpy,!memcpy,!fgets)
```

## `usr/sbin/avahi-dnsconfd`

```
usr/sbin/avahi-dnsconfd: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!fprintf,!strncpy,!snprintf,!memset,!memmove,!printf)
```

## `usr/sbin/dropbear`

```
usr/sbin/dropbear: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fprintf,!strcat,!memcpy,!syslog,!explicit_bzero,!read,!snprintf,!memset,!fgets,!memmove,!vsnprintf,!printf,!strcpy,!gethostname,!strncpy)
```

## `usr/sbin/flash_erase`

```
usr/sbin/flash_erase: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memset,!memcpy,!printf,!read,!strcpy,!fprintf,!sprintf)
```

## `usr/sbin/lighttpd`

```
usr/sbin/lighttpd: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!poll,!memcpy,!fread,!getcwd,!strncpy,!read,!memset,!memmove,!stpcpy,!syslog,!printf,!fprintf)
```

## `usr/sbin/lighttpd-angel`

```
usr/sbin/lighttpd-angel: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!memcpy,!fprintf,!memset)
```

## `usr/sbin/ntpd`

```
usr/sbin/ntpd: +ASLR +STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC +IMMEDIATE-BIND ~FORTIFY-SOURCE(+fprintf,+fdelt,+printf,+memcpy,+strncpy,+longjmp,+syslog,+vfprintf,+sprintf,!getcwd,!poll,!fread,!sprintf,!memset,!memmove,!fprintf,!strcpy,!memcpy,!gethostname,!stpcpy,!fgets,!readlink,!read,!recvfrom,!printf,!strncpy)
```

## `usr/sbin/ubiattach`

```
usr/sbin/ubiattach: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!fprintf,!memcpy,!printf,!memset,!strncpy,!sprintf)
```

## `usr/sbin/ubiformat`

```
usr/sbin/ubiformat: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!fprintf,!memcpy,!sprintf,!strcpy,!printf,!strncpy,!memset)
```

## `usr/sbin/ubimkvol`

```
usr/sbin/ubimkvol: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!fprintf,!strncpy,!printf,!read,!sprintf,!memcpy,!memset)
```

## `usr/sbin/update-daemon`

```
usr/sbin/update-daemon: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!read,!recv,!sprintf,!memset,!printf,!strcpy)
```

## `usr/sbin/visudo`

```
usr/sbin/visudo: !ASLR +STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND ~FORTIFY-SOURCE(+vfprintf,+printf,+memcpy,+fprintf,!memcpy,!read,!fread,!memset,!getdomainname)
```

## `usr/sbin/xtables-legacy-multi`

```
usr/sbin/xtables-legacy-multi: !ASLR !STACK-PROT !EXEC-STACK !SHADOW-STACK !GUARDED-CTRL-STACK !BRANCH-TARGET-ID +READ-ONLY-RELOC !IMMEDIATE-BIND !FORTIFY-SOURCE(!printf,!strncpy,!vfprintf,!strcpy,!snprintf,!fgets,!fprintf,!strncat,!memset,!memcpy)
```
