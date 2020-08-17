#include <stdio.h>

int main() {
    
    long long unsigned hex = 0xf12af4da;
    long long unsigned hex_flipped;
    unsigned bytes[4];
    bytes[0] = hex & 0xff;
    bytes[1] = hex & 0xff00;
    bytes[2] = hex & 0xff0000;
    bytes[3] = hex & 0xff000000;

    printf("the value in hex is %llx\n", hex);
    printf("last byte is %llx\n", bytes[0]);
    printf("third byte is %llx\n", bytes[1]);
    printf("second byte is %llx\n", bytes[2]);
    printf("first byte is %llx\n", bytes[3]);
    int i = 0;
    while (i < 4) {
        hex_flipped = bytes[i];
        hex_flipped = hex_flipped >> 8;
        i++;
    }
    printf("hex value flipped is %llx\n", hex_flipped);
    return 0;
}