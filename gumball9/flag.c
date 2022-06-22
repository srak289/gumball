#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_DATA 33
#define SIZE_FLAG 23
#define KEY "\xba\xbe\xee"
#define SIZE_KEY 3

unsigned char *B64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char charAt(char c) {
    unsigned char *pos;
    pos = strchr(B64, c);
    char x=0;
    if(pos != NULL) {
        x = (char)(pos - B64);    
        return x;
    } else {
        return 0;
    }
}

unsigned char *flag_machine(unsigned char *data, unsigned char *flag) {
    unsigned char *flag_ptr = flag;
    for(int i = 0; i < SIZE_DATA-1; i+=4) {
        // The guys at the lab are looking into new flag transmission techniques...
        // Unfortunately we're not sure what this one is..and the key isn't working on it
        // Can you figure it out? :)

        // B64[somthing]
        // data[i]
        // flag[i] = something
        // hmmm

        //----------
        // Code Here
        //----------
    }
    int keydex = 0;
    for(int i = 0; i < SIZE_DATA-1; i++) {
        flag[i] = flag[i]^KEY[keydex];
        if(keydex < SIZE_KEY-1) {
            keydex++;
        } else {
            keydex=0;
        }
    }
    flag[SIZE_FLAG-1] = 0x00;
    return flag;
}

int main(int argc, char **argv) {
    unsigned char *data = "\x33\x63\x75\x44\x32\x4e\x2b\x43\x31\x73\x57\x73\x32\x38\x32\x4c\x36\x64\x65\x57\x7a\x73\x65\x6f\x31\x63\x75\x63\x78\x77\x3d\x3d\x00";
    unsigned char res[SIZE_FLAG];
    printf("\nHere is the flag:\n\n%s\n", flag_machine(data, res));
}
