#include <stdio.h>

int main(void) {
    char c = (char)0xff; // 255 unsigned, but -1 signed.

    // se represents the sign-extended value.
    int se = c;
    // nse prohibits sign extension by masking the higher-order bits.
    int nse = c & 0xff;

    // first, we show the decimal representations
    printf("c is %d\nse is %d\nnse is %d\n", c, se, nse);
    // then we show how the hex values enlighten the issue.
    printf("c is %02X\nse is %02X\nnse is %02X\n", c, se, nse);
}
