#include <stdio.h>

// Function to reverse the bits of an unsigned integer
unsigned int reverseBits(unsigned int num) {
    unsigned int reversedNum = 0;

    // Iterate through all the bits of num
    for (int i = 0; i < 32; i++) {
        // Shift reversedNum to the left to make space for the next bit
        reversedNum = (reversedNum << 1) | (num & 1);

        // Shift num to the right to check the next bit
        num >>= 1;
    }

    return reversedNum;
}

int main() {
    unsigned int num = 1234567890; // Example number to reverse bits
    unsigned int reversed = reverseBits(num);

    printf("Original number: %u\n", num);
    printf("Reversed bits: %u\n", reversed);

    return 0;
}
