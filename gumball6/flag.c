#include <stdio.h>

#define KEY "jupiter"
#define SIZE_KEY 0
#define SIZE_DATA 0

char *decode_flag(char *data, char *res) {

    int keydex = 0;

    for(int i = 0; i < SIZE_DATA-1; i++) {

        res[i] = data[i] ^ KEY[keydex];

        if(keydex < SIZE_KEY - 1) {
            keydex++;
        } else {
            keydex = 0;
        }
    }

    res[SIZE_DATA-1] = 0x00;

    return res;
}

int main(int argc, char **argv) {

    unsigned char data[SIZE_DATA] = {0x3a, 0x1a, 0x5, 0x7, 0x10, 0x21, 0x17, 0xc, 0x1c, 0x1e, 0xc, 0x00};

    char res[SIZE_DATA];

    printf("\nHere is the flag:\n\ngumball{%s}\n", decode_flag(data, res));
}
