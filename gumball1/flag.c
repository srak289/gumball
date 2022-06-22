#include <stdio.h>

int main(int argc, char **argv) {
    unsigned char data[10] = {0x8e, 0x86, 0x86, 0xa4, 0xea, 0xdc, 0xdc, 0xca, 0xe4, '\0'};
    for(int i=0; i<9; i++) {
        data[i] = data[i]>>1;
    }
    // Running this program will print the flag
    printf("\nHere is the flag:\n\ngumball{%s}\n", data);
}
