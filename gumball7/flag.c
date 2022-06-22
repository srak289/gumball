#include <stdio.h>
#include <stdlib.h>

#define SIZE_DATA 21

char *flag_machine(char *data, char *key) {
    // Oh dear it looks like our flag machine operator lost the key!
    // Fortunately it has a very small keyspace of sixteen bits...
    // Shouldn't take too long to guess! :)
    int keylen=2;
    int keydex=1;
    for(int i = 0; i < SIZE_DATA-1; i++) {
        data[i] = data[i] ^ key[keydex];
        if(keydex > 0) {
            keydex--;
        } else {
            keydex=1;
        }
    }

    return data;
}

int main(int argc, char **argv) {
    unsigned char key[6];
    unsigned char data[SIZE_DATA] = {0x99, 0x98, 0x93, 0x8f, 0x9f, 0x81, 0x92, 0x96, 0xbd, 0x82, 0x93, 0x80, 0x9f, 0x83, 0x9a, 0xa1, 0x97, 0x83, 0x9b, 0x90, 0x00};

    if(argc == 1) {
        printf("Enter the key as an integer from 0 to 65535: ");
        fscanf(stdin, "%d", key);
        atoi(key);
    } else {
        if(*argv[1] == '-') {
            fscanf(stdin, "%d", key);
            atoi(key);
        } else {
            printf("You must either use `-` to read input from stdin or run this program with no arguments\n");
            return 1;
        }
    }

    printf("%s\n", flag_machine(data, key));

    return 0;
}
