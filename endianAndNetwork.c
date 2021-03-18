/* A big endian machine places the most significant byte in the lowest address while 
a little endian machine places the least significant byte in the lowest address.
The socket interface specifies a standard byte ordering called network-byte order 
which happens to be big endian and that's to avoid confusion when communicating 
between different architecture.
*/

#include <stdio.h>

int main() {
    int bytes = 0xa120ffed;
    // Unsigned char pointers are useful to access data byte by byte
    // with vales range of 0 - 255
    unsigned char *ptr = (unsigned char *) &bytes;

    printf("bytes in hex: %x\n", bytes);

    // little endian machine will print: ed ff 20 a1
    // big endian machine will print: a1 20 ff ed
    printf("bytes order:\n");
    for(int i = 0; i < sizeof(int); i++) {
        printf("%x\t",ptr[i]);
    }
    printf("\n");

    // values in network byte order (big endian order)
    // this should not make any changes on a machine 
    // with a big endian processor
    bytes = htonl(bytes);
    printf("\nAfter htonl()\n");
    printf("bytes in hex: %x\n", bytes);
    printf("bytes order:\n");
    for(int i = 0; i < sizeof(int); i++) {
        printf("%x\t",ptr[i]);
    }
    printf("\n");

    return 0;
}