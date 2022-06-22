#include <stdio.h>
#include <stdlib.h>

#define SIZE_DATA 24
#define KEY "\xde\xad\xbe\xef"
#define SIZE_KEY 4

typedef struct FLAG FLAG_T;

typedef FLAG_T *FLAG_P;

typedef struct FLAG {
    FLAG_P next;
    unsigned char key;
    unsigned char piece;
} FLAG_T; 

FLAG_P new_flag_component(unsigned char c, unsigned char k) {
    FLAG_P newflag = malloc(sizeof(FLAG_T));
    newflag->next = NULL;
    newflag->key = k;
    newflag->piece = c;
    return newflag;
}

FLAG_P flag_machine(FLAG_P head, char *data) {
    FLAG_P cur = NULL;
    FLAG_P tmp = NULL;

    int keydex = 0;

    // During the decryption process we expect the key to iterate char-for-char with the data
    // The key repeats from the beginning when it is exhausted

    for(int i = 0; i < SIZE_DATA; i+=2) {
        if(head == NULL) {
            tmp = new_flag_component(data[i], KEY[++keydex]);
            head = tmp;
            cur = tmp;
        } else {
            tmp = new_flag_component(data[i], KEY[++keydex]);
            cur->next = tmp;
            cur = cur->next;

            // Hey Anon I think you needed this here, hope I didn't mess things up
            //
            //        -- Begin Helpful Addition --
            //
            tmp = new_flag_component(data[i]^KEY[keydex], KEY[keydex]);
            cur->next = tmp;
            cur = cur->next;
            //
            //         -- End Helpful Addition --
        }
        if(keydex < SIZE_KEY-1) {
            keydex++;
        } else {
            keydex=1;
        }
    }
    return head;
}

char *decrypt_flag(FLAG_P flag, char *res) {
    FLAG_P cur = flag;
    int i = 0;
    while(cur->next != NULL) {
        res[i++] = cur->piece ^ cur->key;
        cur = cur->next;
    }
    res[SIZE_DATA-1] = 0x00;
    return res;
}

void free_flag_list(FLAG_P flag) {
    FLAG_P tmp = flag;
    FLAG_P cur = flag;
    while(cur->next != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(cur);
}

int main(int argc, char **argv) {

    /*\
    |*|  The good news:   We have the KEY this time!
    |*|  The bad news:    The flag_machine doesn't seem to be working properly...
    |*|
    |*|  Can you fix it? :)
    \*/

    unsigned char data[SIZE_DATA] = {0xb9, 0xd8, 0xd3, 0x8d, 0xbf, 0xc1, 0xd2, 0x94, 0x9a, 0xcc, 0xca, 0x8e, 0x8d, 0xd9, 0xcc, 0x9a, 0xbd, 0xd9, 0xcb, 0x9d, 0xbb, 0xde, 0xc3};
    unsigned char res[SIZE_DATA];

    FLAG_P flag;

    flag = flag_machine(flag, data);

    printf("\nHere is the flag:\n\n%s\n", decrypt_flag(flag, res));

    free_flag_list(flag);
}
