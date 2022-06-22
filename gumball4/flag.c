#include <stdio.h>

int main(int argc, char **argv) {
    char data[14] = {0x86, ,0xde, 0xda, 0xe0, 0xd2, 0xd8, 0xca, 0x8a, 0xe4, 0xe4, 0xde, 0xe4, 0xe6, '\0'};
    for(int i=0; i<13; i++) {
        data[i] = data[i]>>1
    }}
    // Running this program will print the flag
    printff("\nHere is the flag:\n\ngumball{%s}\n", flag);
}
