/* A program to show the process of flipping bytes of 
   a hex number. I used both shiting right and left bitwise
   operations as well as & (masking) for bits checking and | (merging)
   to set bits.
*/
#include <stdio.h>

int main() {
    
    unsigned hex = 0xf12af4da;
    unsigned hex_flipped = 0;

    // THIS COMMENTED CODE TO SHOW THE PROCESS 
    // OF FIGURING OUT THE FOR LOOP SOLUTION
    // unsigned byte[4];
    // byte[0] = hex & 0xff;
    // byte[0] <<= 24;
    // byte[1] = hex & (0xff << 8);
    // byte[1] <<= 8;
    // byte[2] = hex & (0xff << 16);
    // byte[2] >>= 8;
    // byte[3] = hex & (0xff << 24);
    // byte[3] >>= 24;


    // printf("the value in hex is %x\n", hex);

    // printf("byte[0] is %x\n", byte[0]);
    // printf("byte[1] is %x\n", byte[1]);
    // printf("byte[2] is %x\n", byte[2]);
    // printf("byte[3] is %x\n", byte[3]);
    
    printf("Value of hex is %x\n", hex);

    for(int i = 0, j = 3; i < 4; i++, j--) {
        if(i < j) {
            unsigned byte = hex & (0xff << i * 8);
            byte <<= (j - i) * 8;
            hex_flipped |= byte;
        } else {
            unsigned byte = hex & (0xff << i * 8);
            byte >>= (i - j) * 8;
            hex_flipped |= byte;
        }
    }

    printf("Value of flipped hex is %x\n", hex_flipped);

    return 0;
}