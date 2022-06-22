#include <stdio.h>

int main(int argc, char **argv) {
    unsigned char data[19] = {0x98, '\0', 0xd2, 0xdc, 0xca, '\0', 0xa8, 0xca, 0xe4, '\0', 0xda, 0xd2, '\0', 0xdc, 0xc2, 0xe8, 0xde, 0xe4, '\0'};
    for(int i=0; i<18; i++) {
        data[i] = data[i]>>1;
    }
    // Running this program will print the flag
    printf("\nHere is the flag:\n\ngumball{%s}\n", data);
}
