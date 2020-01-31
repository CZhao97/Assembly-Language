
#include <stdio.h>

void proc1(char *, int *, int *);

void main() {
    char buf[40];
    int x = 6;
    int y = 9;

    printf("Original values are: x=%d, y=%d.\n", x, y);
    proc1(buf, &x, &y);
    printf("Final values are: x=%d, y=%d.\n", x, y);
    puts(buf);
    return;
}

