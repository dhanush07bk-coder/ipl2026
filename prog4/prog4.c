#include <stdio.h>

/* Structure with bit-fields */
struct Bitfield {
    unsigned int firstbit  : 1;
    unsigned int secondbit : 1;
    unsigned int thirdbit  : 1;
    unsigned int number    : 5;
};

int main() {

    struct Bitfield a;

    /* Assign values */
    a.firstbit = 1;
    a.secondbit = 0;
    a.thirdbit = 1;
    a.number = 17;

    /* Display values */
    printf("First Bit  = %u\n", a.firstbit);
    printf("Second Bit = %u\n", a.secondbit);
    printf("Third Bit  = %u\n", a.thirdbit);
    printf("Number     = %u\n", a.number);

    return 0;
}