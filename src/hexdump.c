#include <stdio.h>
#include <stdlib.h>

void hexDump(const unsigned char bytes[], long length) {
    // we and with 0xff to mask off the bits when sign-extended.
    int start = bytes[1] * 256 + bytes[0];
    printf("%d\n", start);
    int pc = start, c = 0, x;
    unsigned char chars[10] = {0};

    for (x = 2; x < length; x++) {
        // make it pretty
        if ( (pc - start) % 8 == 0 ) {
            // chars are built during each iteration, but
            // printed when we reach the end of the line.
            printf(" %s", chars);
            printf("\n%04X:", pc);
            c = 0;
        }
        unsigned char ch = bytes[x];
        // build the chars - only printable chars
        chars[c++] = ( ch >= 32 && ch <= 127 ) ? ch : '.';

        printf(" %02X", bytes[x]);
        pc++;
    }

    // fix final row
    int last = (pc - start) % 8;
    chars[c] = '\0';
    for (x = 0; x < 8-last; x++)
        printf("   ");
    printf(" %s\n", chars);
}

int main(void)  {
    FILE *fp;
    const char *fname = "../data/mult.prg";
    unsigned char *file;

    // open file
    if ( (fp = fopen(fname, "r")) == NULL ) {
        fprintf(stderr, "Cannot open %s.\n", fname);
        return(1);
    }

    // find the file size
    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);

    // allocate memory for the file - no error checking
    if ( (file = malloc(len + 1)) == NULL ) {
        fprintf(stderr, "Cannot allocate memory for file.\n");
        return(2);
    }

    // Read the file into the char array
    rewind(fp);
    fread(file, len, 1, fp);
    fclose(fp);

    hexDump(file, len);
    free(file);
}
