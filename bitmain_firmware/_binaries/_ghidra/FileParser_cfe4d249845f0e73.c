// Decompiled: FileParser_cfe4d249845f0e73

void _DT_INIT(void)

{
    FUN_00010868();
    return;
}

void entry(undefined4 param_1)

{
    undefined4 in_stack_00000000;

    __libc_start_main(FUN_00011f90, in_stack_00000000, &stack0x00000004,
                      0x122fd, &DAT_00012339, param_1);
    /* WARNING: Subroutine does not return */
    abort();
}

/* WARNING: Removing unreachable block (ram,0x0001087c) */

void FUN_00010868(void)

{
    __gmon_start__();
    return;
}

/* WARNING: Removing unreachable block (ram,0x000108a0) */
/* WARNING: Removing unreachable block (ram,0x000108aa) */

void FUN_0001088c(void)

{
    return;
}

/* WARNING: Removing unreachable block (ram,0x000108cc) */
/* WARNING: Removing unreachable block (ram,0x000108d6) */

void FUN_000108b0(void)

{
    return;
}

void _FINI_0(void)

{
    if (DAT_00023838 == '\0') {
        FUN_0001088c();
        DAT_00023838 = '\x01';
    }
    return;
}

void FUN_000108f8(undefined4 param_1)

{
    puts("Useage:\r");
    printf("\t%s [option] [paramaters]\n\n", param_1);
    puts("\tOption:{-f} {-s} {-p} {-n} {-x} {-q}\n");
    puts("\t\t-f [minerType] [fileName] [rootPublicKeyFile]: \n\t\t\tOnly "
         "Check If Filename was Valided.\n");
    puts("\t\t-s [minerType] [fileName] [rootPublicKeyFile]: \n\t\t\tCheck If "
         "Filename Was Valided, and Splite Bmu To \"/tmp/tmpfw/\"\n");
    puts("\t\t-p [minerType] [fileName] [rootPublicKeyFile]: \n\t\t\tCheck If "
         "Filename Was Valided, and Dump BmuComments\n");
    puts("\t\t-x [minerType] [fileName] [rootPublicKeyFile]: \n\t\t\tCheck If "
         "Filename Was FullSize BMU\n");
    puts("\t\t-n [nandBinFile]: \n\t\t\tSplite SigImg To Single File To "
         "\"/tmp/tmpNand/\"\n");
    puts("\t\t-q: \n\t\t\tGenerate A 256Bytes 0xff File To \"/tmp/256BFF\"\n");
    puts("\tReturns:");
    puts("\t\t0: \n\t\t\tWell Done!\n");
    puts("\t\tOthers: \n\t\t\tSomething Wrong!\n");
    return;
}

undefined4 FUN_000109a8(char *param_1)

{
    undefined4 uVar1;
    undefined4 local_8014;
    undefined1 auStack_8010[32764];
    FILE *local_14;
    FILE *local_10;
    int local_c;

    local_8014 = 0;
    memset(auStack_8010, 0, 0x7ffc);
    local_10 = fopen64(param_1, "rb");
    if (local_10 == (FILE *)0x0) {
        puts("Load Nand Image File Failed!");
        uVar1 = 1;
    } else {
        for (local_c = 0; local_c < 0xf; local_c = local_c + 1) {
            fread(&local_8014, *(size_t *)(&DAT_0002307c + local_c * 0x84), 1,
                  local_10);
            local_14 = fopen64(s__tmp_tmpNand_devicetree_dtb_sig_00023080 +
                                   local_c * 0x84,
                               "wb");
            if (local_14 == (FILE *)0x0) {
                printf("Try To Write To File \'%s\' Failed!\n",
                       s__tmp_tmpNand_devicetree_dtb_sig_00023080 +
                           local_c * 0x84);
                if (local_10 != (FILE *)0x0) {
                    fclose(local_10);
                }
                return 2;
            }
            fwrite(&local_8014, *(size_t *)(&DAT_0002307c + local_c * 0x84), 1,
                   local_14);
            if (local_14 != (FILE *)0x0) {
                fclose(local_14);
            }
            local_14 = (FILE *)0x0;
        }
        if (local_10 != (FILE *)0x0) {
            fclose(local_10);
        }
        uVar1 = 0;
    }
    return uVar1;
}

undefined4 FUN_00010b9c(void)

{
    undefined4 uVar1;
    undefined4 local_110;
    undefined1 auStack_10c[252];
    FILE *local_10;
    int local_c;

    local_10 = fopen64("/tmp/256BFF", "wb");
    if (local_10 == (FILE *)0x0) {
        puts("GenFile Failed!");
        uVar1 = 1;
    } else {
        local_110 = 0;
        memset(auStack_10c, 0, 0xfc);
        for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
            auStack_10c[local_c + -4] = 0xff;
        }
        fwrite(&local_110, 0x100, 1, local_10);
        fclose(local_10);
        uVar1 = 0;
    }
    return uVar1;
}

undefined4 FUN_00010c70(void *param_1, size_t param_2, uchar *param_3,
                        void *param_4)

{
    ulong uVar1;
    char *pcVar2;
    undefined4 uVar3;
    SHA256_CTX SStack_a4;
    uchar auStack_34[32];
    int local_14;
    RSA *local_10;
    BIO *local_c;

    local_c = (BIO *)0x0;
    local_10 = (RSA *)0x0;
    local_c = BIO_new_mem_buf(param_4, 0x400);
    local_10 = PEM_read_bio_RSA_PUBKEY(local_c, (RSA **)0x0, (undefined1 *)0x0,
                                       (void *)0x0);
    if (local_10 == (RSA *)0x0) {
        uVar1 = ERR_get_error();
        pcVar2 = ERR_error_string(uVar1, (char *)0x0);
        printf("OpenSSL error: %s\n", pcVar2);
        puts("Read Root PubK Failed!");
        uVar3 = 0xc;
    } else {
        SHA256_Init(&SStack_a4);
        SHA256_Update(&SStack_a4, param_1, param_2);
        SHA256_Final(auStack_34, &SStack_a4);
        local_14 =
            RSA_verify(0x2a0, auStack_34, 0x20, param_3, 0x100, local_10);
        if (local_10 != (RSA *)0x0) {
            RSA_free(local_10);
        }
        if (local_c != (BIO *)0x0) {
            BIO_free(local_c);
        }
        if (local_14 == 1) {
            uVar3 = 0;
        } else {
            uVar1 = ERR_get_error();
            pcVar2 = ERR_error_string(uVar1, (char *)0x0);
            printf("OpenSSL error: %s\n", pcVar2);
            puts("Check miner.pem Failed!");
            uVar3 = 0xd;
        }
    }
    return uVar3;
}

undefined4 FUN_00010de8(FILE *param_1, int param_2, undefined4 *param_3,
                        undefined1 param_4, char param_5, char param_6)

{
    size_t sVar1;
    char local_524[128];
    undefined4 local_4a4;
    undefined4 local_4a0;
    undefined4 local_49c;
    undefined4 local_498;
    undefined4 local_494;
    undefined4 local_490;
    undefined4 local_48c;
    undefined4 local_488;
    SHA256_CTX SStack_484;
    undefined4 local_414;
    undefined1 auStack_410[1020];
    size_t local_14;
    FILE *local_10;
    int local_c;

    local_414 = 0;
    memset(auStack_410, 0, 0x3fc);
    SHA256_Init(&SStack_484);
    local_c = 0;
    local_14 = 0;
    local_10 = (FILE *)0x0;
    if (param_6 != '\0') {
        builtin_strncpy(local_524, "/tmp/tmpfw/", 0xc);
        memset(local_524 + 0xc, 0, 0x74);
        switch (param_4) {
        case 0:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "BOOT.bin", 9);
            break;
        case 1:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "devicetree.dtb", 0xf);
            break;
        case 2:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "uImage", 7);
            break;
        case 3:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "minerfs.image.gz", 0x11);
            break;
        case 4:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "update.image.gz", 0x10);
            break;
        case 5:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "crl.tar.gz", 0xb);
            break;
        case 6:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "miner.btm.tar.gz", 0x11);
            break;
        case 7:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "reserve", 8);
            break;
        case 9:
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, "datafile", 9);
        }
        if (param_5 != '\0') {
            sVar1 = strlen(local_524);
            builtin_strncpy(local_524 + sVar1, ".sig", 5);
        }
        printf("fileName:\'%s\', size:[%d]\r\n", local_524, param_2);
        local_10 = fopen64(local_524, "wb");
        if (local_10 == (FILE *)0x0) {
            printf("Create File \'%s\' Failed!\r\n", local_524);
        }
    }
    while (0x400 < (uint)(param_2 - local_c)) {
        local_14 = fread(&local_414, 1, 0x400, param_1);
        local_c = local_c + local_14;
        SHA256_Update(&SStack_484, &local_414, 0x400);
        if ((param_6 != '\0') && (local_10 != (FILE *)0x0)) {
            fwrite(&local_414, 1, 0x400, local_10);
        }
    }
    local_14 = fread(&local_414, 1, param_2 - local_c, param_1);
    SHA256_Update(&SStack_484, &local_414, local_14);
    if ((param_6 != '\0') && (local_10 != (FILE *)0x0)) {
        fwrite(&local_414, 1, local_14, local_10);
    }
    local_4a4 = 0;
    local_4a0 = 0;
    local_49c = 0;
    local_498 = 0;
    local_494 = 0;
    local_490 = 0;
    local_48c = 0;
    local_488 = 0;
    SHA256_Final((uchar *)&local_4a4, &SStack_484);
    if ((param_6 != '\0') && (local_10 != (FILE *)0x0)) {
        fclose(local_10);
    }
    *param_3 = local_4a4;
    param_3[1] = local_4a0;
    param_3[2] = local_49c;
    param_3[3] = local_498;
    param_3[4] = local_494;
    param_3[5] = local_490;
    param_3[6] = local_48c;
    param_3[7] = local_488;
    return local_488;
}

int FUN_00011460(char *param_1, char *param_2, char *param_3, char param_4,
                 char param_5, char param_6)

{
    ulong uVar1;
    char *pcVar2;
    char local_bec[260];
    SHA256_CTX SStack_ae8;
    uchar local_a78[32];
    undefined4 local_a58;
    undefined1 auStack_a54[252];
    SHA256_CTX SStack_958;
    uchar auStack_8e8[1056];
    undefined4 local_4c8;
    undefined1 auStack_4c4[1020];
    undefined1 auStack_c8[48];
    int local_98;
    uint local_60;
    uint local_5c;
    int local_58;
    RSA *local_54;
    BIO *local_50;
    FILE *local_4c;
    FILE *local_48;
    int local_44;
    uint local_40;
    FILE *local_3c;
    uint local_38;
    ushort local_32;
    FILE *local_30;
    int local_2c;
    int local_28;
    int local_24;
    int local_20;
    int local_1c;
    uint local_18;
    byte local_11;

    FUN_0001233c(param_1, auStack_c8);
    local_2c = local_98;
    if (local_98 < 0x800) {
        printf("File \'%s\' Not Enough %d, Something Wrong!\n", param_1, 0x800);
        local_44 = 6;
    } else {
        local_30 = fopen64(param_1, "rb");
        if (local_30 == (FILE *)0x0) {
            printf("Read File \'%s\' Failed!\n", param_1);
            local_44 = 7;
        } else {
            fread(param_3, 0x800, 1, local_30);
            if (*param_3 == '&') {
                local_11 = 0;
                local_32 = CONCAT11(param_3[0xb], param_3[0xc]);
                if ((param_6 == '\0') ||
                    (printf("content:%x\n", (uint)local_32),
                     (local_32 & 0xfe00) == 0xfe00)) {
                    for (local_18 = 0; (int)local_18 < 0x10;
                         local_18 = local_18 + 1) {
                        if (((int)(uint)local_32 >> (local_18 & 0xff) & 1U) !=
                            0) {
                            local_11 = local_11 + 1;
                        }
                    }
                    if (local_11 == param_3[0x518]) {
                        local_1c = ((byte)param_3[0x518] + 9) * 0x100;
                        local_38 = (uint)(byte)param_3[0x519] << 0x18 |
                                   (uint)(byte)param_3[0x51a] << 0x10 |
                                   (uint)(byte)param_3[0x51b] << 8 |
                                   (uint)(byte)param_3[0x51c];
                        for (local_20 = 0; local_20 < (int)(uint)local_11;
                             local_20 = local_20 + 1) {
                            local_60 =
                                (uint)(byte)param_3[local_20 * 5 + 0x51e]
                                    << 0x18 |
                                (uint)(byte)param_3[local_20 * 5 + 0x51f]
                                    << 0x10 |
                                (uint)(byte)param_3[local_20 * 5 + 0x520] << 8 |
                                (uint)(byte)param_3[local_20 * 5 + 0x521];
                            local_1c = local_1c + local_60;
                            printf("file[%d] size:[%d]\n", local_20, local_60);
                        }
                        if (local_1c == local_2c) {
                            local_3c = fopen64(param_2, "r");
                            if (local_3c == (FILE *)0x0) {
                                printf("Cannot Open Root PublicKey \'%s\'!\n",
                                       param_2);
                                if (local_30 != (FILE *)0x0) {
                                    fclose(local_30);
                                }
                                local_44 = 0xb;
                            } else {
                                local_4c8 = 0;
                                memset(auStack_4c4, 0, 0x3fc);
                                fread(&local_4c8, 0x400, 1, local_3c);
                                fclose(local_3c);
                                local_3c = (FILE *)0x0;
                                local_40 = (uint)CONCAT11(param_3[0x16],
                                                          param_3[0x17]);
                                local_44 =
                                    FUN_00010c70(param_3 + 0x18, local_40,
                                                 param_3 + 0x418, &local_4c8);
                                if (local_44 == 0) {
                                    local_48 =
                                        fopen64("/usr/bin/fw_version", "w");
                                    if (local_48 != (FILE *)0x0) {
                                        printf(
                                            "fw version data: %02X %02X %02X "
                                            "%02X %02X %02X %02X %02X\n",
                                            (uint)(byte)param_3[0xd],
                                            (uint)(byte)param_3[0xe],
                                            (uint)(byte)param_3[0xf],
                                            (uint)(byte)param_3[0x10],
                                            (uint)(byte)param_3[0x11],
                                            (uint)(byte)param_3[0x12],
                                            (uint)(byte)param_3[0x13],
                                            (uint)(byte)param_3[0x14]);
                                        fwrite(param_3 + 0xd, 1, 8, local_48);
                                        fclose(local_48);
                                    }
                                    if (param_4 != '\0') {
                                        local_4c = fopen64(
                                            "/tmp/tmpfw/miner.pem", "w");
                                        if (local_4c == (FILE *)0x0) {
                                            puts("Dump Miner.pem Failed!\r");
                                            return 0xf;
                                        }
                                        fwrite(param_3 + 0x18, 1, local_40,
                                               local_4c);
                                        fclose(local_4c);
                                        local_4c = fopen64(
                                            "/tmp/tmpfw/miner.pem.sig", "w");
                                        if (local_4c == (FILE *)0x0) {
                                            puts(
                                                "Dump Miner.pem.sig Failed!\r");
                                            return 0x10;
                                        }
                                        fwrite(param_3 + 0x418, 1, 0x100,
                                               local_4c);
                                        fclose(local_4c);
                                    }
                                    memset(auStack_8e8, 0, 0x420);
                                    SHA256_Init(&SStack_958);
                                    SHA256_Update(&SStack_958, param_3, 0x800);
                                    SHA256_Final(auStack_8e8, &SStack_958);
                                    for (local_24 = 0;
                                         local_24 < (int)(uint)local_11;
                                         local_24 = local_24 + 1) {
                                        local_5c =
                                            (uint)(byte)param_3[local_24 * 5 +
                                                                0x51e]
                                                << 0x18 |
                                            (uint)(byte)param_3[local_24 * 5 +
                                                                0x51f]
                                                << 0x10 |
                                            (uint)(byte)param_3[local_24 * 5 +
                                                                0x520]
                                                << 8 |
                                            (uint)(byte)
                                                param_3[local_24 * 5 + 0x521];
                                        FUN_00010de8(
                                            local_30, local_5c,
                                            auStack_8e8 + (local_24 + 1) * 0x20,
                                            param_3[local_24 * 5 + 0x51d], 0,
                                            param_4);
                                    }
                                    for (local_28 = 0;
                                         local_28 < (int)(uint)local_11;
                                         local_28 = local_28 + 1) {
                                        FUN_00010de8(
                                            local_30, 0x100,
                                            auStack_8e8 +
                                                (local_11 + 1 + local_28) *
                                                    0x20,
                                            param_3[local_28 * 5 + 0x51d], 1,
                                            param_4);
                                    }
                                    local_a58 = 0;
                                    memset(auStack_a54, 0, 0xfc);
                                    fseek(local_30, -0x100, 2);
                                    fread(&local_a58, 0x100, 1, local_30);
                                    local_a78[0] = '\0';
                                    local_a78[1] = '\0';
                                    local_a78[2] = '\0';
                                    local_a78[3] = '\0';
                                    local_a78[4] = '\0';
                                    local_a78[5] = '\0';
                                    local_a78[6] = '\0';
                                    local_a78[7] = '\0';
                                    local_a78[8] = '\0';
                                    local_a78[9] = '\0';
                                    local_a78[10] = '\0';
                                    local_a78[0xb] = '\0';
                                    local_a78[0xc] = '\0';
                                    local_a78[0xd] = '\0';
                                    local_a78[0xe] = '\0';
                                    local_a78[0xf] = '\0';
                                    local_a78[0x10] = '\0';
                                    local_a78[0x11] = '\0';
                                    local_a78[0x12] = '\0';
                                    local_a78[0x13] = '\0';
                                    local_a78[0x14] = '\0';
                                    local_a78[0x15] = '\0';
                                    local_a78[0x16] = '\0';
                                    local_a78[0x17] = '\0';
                                    local_a78[0x18] = '\0';
                                    local_a78[0x19] = '\0';
                                    local_a78[0x1a] = '\0';
                                    local_a78[0x1b] = '\0';
                                    local_a78[0x1c] = '\0';
                                    local_a78[0x1d] = '\0';
                                    local_a78[0x1e] = '\0';
                                    local_a78[0x1f] = '\0';
                                    SHA256_Init(&SStack_ae8);
                                    SHA256_Update(&SStack_ae8, auStack_8e8,
                                                  (uint)local_11 * 0x40 + 0x20);
                                    SHA256_Final(local_a78, &SStack_ae8);
                                    local_50 = (BIO *)0x0;
                                    local_54 = (RSA *)0x0;
                                    local_50 =
                                        BIO_new_mem_buf(param_3 + 0x18, 0x400);
                                    local_54 = PEM_read_bio_RSA_PUBKEY(
                                        local_50, (RSA **)0x0,
                                        (undefined1 *)0x0, (void *)0x0);
                                    if (local_54 == (RSA *)0x0) {
                                        uVar1 = ERR_get_error();
                                        pcVar2 = ERR_error_string(uVar1,
                                                                  (char *)0x0);
                                        printf("OpenSSL error: %s\n", pcVar2);
                                        puts("Load Pem Failed!");
                                        local_44 = 0x11;
                                    } else {
                                        local_58 =
                                            RSA_verify(0x2a0, local_a78, 0x20,
                                                       (uchar *)&local_a58,
                                                       0x100, local_54);
                                        if (local_54 != (RSA *)0x0) {
                                            RSA_free(local_54);
                                        }
                                        if (local_50 != (BIO *)0x0) {
                                            BIO_free(local_50);
                                        }
                                        if (local_58 == 1) {
                                            if (local_30 != (FILE *)0x0) {
                                                fclose(local_30);
                                            }
                                            local_30 = (FILE *)0x0;
                                            puts("All Done!\r");
                                            if (param_5 != '\0') {
                                                puts("This Comment Of This "
                                                     "Package:");
                                                local_bec[0] = '\0';
                                                local_bec[1] = '\0';
                                                local_bec[2] = '\0';
                                                local_bec[3] = '\0';
                                                memset(local_bec + 4, 0, 0xfd);
                                                memcpy(local_bec,
                                                       param_3 + 0x550, 0x100);
                                                puts(local_bec);
                                            }
                                            local_44 = 0;
                                        } else {
                                            puts("Check File Sig failed!\r");
                                            uVar1 = ERR_get_error();
                                            pcVar2 = ERR_error_string(
                                                uVar1, (char *)0x0);
                                            printf("OpenSSL error: %s\n",
                                                   pcVar2);
                                            local_44 = 0x12;
                                        }
                                    }
                                } else {
                                    printf(
                                        "Check pem payload failed! ret:[%d]\n",
                                        local_44);
                                    if (local_30 != (FILE *)0x0) {
                                        fclose(local_30);
                                    }
                                }
                            }
                        } else {
                            printf("Check FileSize Failed, FileSize Should Be "
                                   "[%d]Bytes, But It Was [%d] Bytes, And "
                                   "Total Says[%d]\n",
                                   local_38, local_2c, local_1c);
                            if (local_30 != (FILE *)0x0) {
                                fclose(local_30);
                            }
                            local_44 = 10;
                        }
                    } else {
                        printf("Content Doesn\'t Match![%d][%d]\n",
                               (uint)(byte)param_3[0x518], (uint)local_11);
                        if (local_30 != (FILE *)0x0) {
                            fclose(local_30);
                        }
                        local_44 = 9;
                    }
                } else {
                    puts("This Package Was Not Full Package!");
                    local_44 = 0x14;
                }
            } else {
                printf("\'%s\' Not A Btmu File!\n", param_1);
                if (local_30 != (FILE *)0x0) {
                    fclose(local_30);
                }
                local_44 = 8;
            }
        }
    }
    return local_44;
}

undefined4 FUN_00011f90(int param_1, undefined4 *param_2)

{
    size_t sVar1;
    undefined1 auStack_a10[256];
    undefined1 auStack_910[2048];
    char local_110[128];
    char local_90[128];
    undefined4 local_10;
    char local_b;
    char local_a;
    undefined1 local_9;

    if (param_1 < 2) {
        FUN_000108f8(*param_2);
        local_10 = 1;
    } else if (*(char *)param_2[1] == '-') {
        local_90[0] = '\0';
        local_90[1] = '\0';
        local_90[2] = '\0';
        local_90[3] = '\0';
        memset(local_90 + 4, 0, 0x7c);
        local_110[0] = '\0';
        local_110[1] = '\0';
        local_110[2] = '\0';
        local_110[3] = '\0';
        memset(local_110 + 4, 0, 0x7c);
        memset(auStack_910, 0, 0x800);
        local_9 = 0;
        local_a = '\0';
        local_b = '\0';
        memset(auStack_a10, 0, 0xfd);
        if (param_1 == 5) {
            sVar1 = strlen((char *)param_2[3]);
            if (0x7f < sVar1) {
                puts("fileName Too Long!");
                return 3;
            }
            strcpy(local_90, (char *)param_2[3]);
            sVar1 = strlen((char *)param_2[4]);
            if (0x7f < sVar1) {
                puts("pemName Too Long!");
                return 4;
            }
            strcpy(local_110, (char *)param_2[4]);
        } else if (param_1 == 3) {
            sVar1 = strlen((char *)param_2[2]);
            if (0x7f < sVar1) {
                puts("fileName Too Long!");
                return 3;
            }
            strcpy(local_90, (char *)param_2[2]);
        } else if (param_1 != 2) {
            puts("Param Err!");
            FUN_000108f8(*param_2);
            return 3;
        }
        local_10 = 0;
        switch (*(undefined1 *)(param_2[1] + 1)) {
        default:
            puts("Command Not Support!");
            FUN_000108f8(*param_2);
            local_10 = 5;
            break;
        case 0x6e:
            local_10 = FUN_000109a8(local_90);
            break;
        case 0x71:
            local_10 = FUN_00010b9c();
            break;
        case 0x78:
            local_b = '\x01';
        case 0x70:
            if (local_b == '\0') {
                local_a = '\x01';
            }
        case 0x73:
            if (local_a == '\0') {
                local_9 = 1;
            }
        case 0x66:
            local_10 = FUN_00011460(local_90, local_110, auStack_910, local_9,
                                    local_a, local_b);
        }
    } else {
        FUN_000108f8(*param_2);
        local_10 = 2;
    }
    return local_10;
}

void FUN_000122fc(undefined4 param_1, undefined4 param_2, undefined4 param_3,
                  undefined4 param_4)

{
    int iVar1;
    undefined **ppuVar2;

    _DT_INIT();
    iVar1 = 0;
    ppuVar2 = &__DT_INIT_ARRAY;
    do {
        iVar1 = iVar1 + 1;
        (*(code *)*ppuVar2)(param_1, param_2, param_3, *ppuVar2, param_4);
        ppuVar2 = ppuVar2 + 1;
    } while (iVar1 != 1);
    return;
}

void FUN_0001233c(char *param_1, stat64 *param_2)

{
    __xstat64(3, param_1, param_2);
    return;
}

void _DT_FINI(void)

{
    return;
}
