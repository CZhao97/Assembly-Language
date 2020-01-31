# 1 "subprog.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "subprog.c"
typedef unsigned short bit16;
char *cvt2bitstr(bit16 x, char* str) {
    int i;
    for (i = 0; i < 16; i++) {
        str[i] = (char) ((x & 0x8000) >> 15) | 0x30;
        x = (x << 1) & 0xffff;
    }
    str[16] = '\0';
    return;
}
