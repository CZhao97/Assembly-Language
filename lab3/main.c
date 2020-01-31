
#include <stdio.h>

int get_byte_by_addr(int *, int i);

int get_byte_by_order(int x, int i) {
    // complete this in Part 2.
	x= (x>>8*i)&0xff;
    return x;
    // end of Part 2.
}

int x=0x01234567;
unsigned int y=0xffffffd6;

void main () {
    // complete this in Part 1.
    printf("x = %#.08x\n", x);
    printf("x = %d\n", x);
    printf("y = %#.08x\n", y);
    printf("y = %u\n", y);
    // end of Part 1

    int i;

    printf("x = ");
    for (i = 0; i < 4; i++) {
        printf("%02x", get_byte_by_order(x, i));
    }
    putchar('\n');

    printf("x = ");
    for (i = 0; i < 4; i++) {
        printf("%02x", get_byte_by_addr(&x, i));
    }
    putchar('\n');

    printf("y = ");
    for (i = 0; i < 4; i++) {
        printf("%02x", get_byte_by_order(y, i));
    }
    putchar('\n');

    printf("y = ");
    for (i = 0; i < 4; i++) {
        printf("%02x", get_byte_by_addr(&y, i));
    }
    putchar('\n');

    return;
}

