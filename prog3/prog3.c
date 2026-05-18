#include <stdio.h>

/* Function to print bits of integer */
void printIntBits(int n) {

    int i;

    for(i = 31; i >= 0; i--) {

        printf("%d", (n >> i) & 1);

        if(i % 8 == 0)
            printf(" ");
    }

    printf("\n");
}

/* Function to count number of 1 bits */
int countOneBits(unsigned int n) {

    int count = 0;

    while(n) {
        count += n & 1;
        n = n >> 1;
    }

    return count;
}

/* Function to check endian */
void checkEndian() {

    int n = 1;

    char *ptr = (char *)&n;

    if(*ptr == 1)
        printf("System is Little Endian\n");
    else
        printf("System is Big Endian\n");
}

/* Function to print float bits */
void printFloatBits(float f) {

    unsigned int *ptr = (unsigned int *)&f;

    int i;

    for(i = 31; i >= 0; i--) {

        printf("%d", (*ptr >> i) & 1);

        if(i == 31 || i == 23)
            printf(" ");
    }

    printf("\n");
}

int main() {

    int intNum, negInt;
    float floatNum, negFloat;

    /* Integer bits */
    printf("Enter an integer: ");
    scanf("%d", &intNum);

    printf("\nBits of %d:\n", intNum);
    printIntBits(intNum);

    printf("Number of 1 bits = %d\n",
           countOneBits((unsigned int)intNum));

    /* Endian check */
    printf("\n");
    checkEndian();

    /* Negative integer */
    printf("\nEnter a negative integer: ");
    scanf("%d", &negInt);

    printf("\nBits of %d:\n", negInt);
    printIntBits(negInt);

    /* Floating point */
    printf("\nEnter a floating point number: ");
    scanf("%f", &floatNum);

    printf("\nBits of %f:\n", floatNum);
    printFloatBits(floatNum);

    /* Negative floating point */
    printf("\nEnter a negative floating point number: ");
    scanf("%f", &negFloat);

    printf("\nBits of %f:\n", negFloat);
    printFloatBits(negFloat);

    return 0;
}