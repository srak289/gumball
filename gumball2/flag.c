#include <stdio.h>

int main(int argc, char **argv) {
    unsigned char data[14] = {0x8e, 0xca, 0xdc, 0xca, 0xe4, 0xc2, 0xd8, 0xa4, 0xca, 0xe0, 0xc2, 0xd2, 0xe4, '\0'};
    for(int i=0; i<13; i+=2) {
        data[i] = data[i]>>1;
    }
    // Running this program will print the flag
    printf("\nHere is the flag:\n\ngumball{%s}\n", data);
}
