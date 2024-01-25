#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;

uint32_t reverseByteOrder(uint32_t input) {
    uint32_t output;

    output = (input & 0x000000FF) << 24 |
             (input & 0x0000FF00) << 8 |
             (input & 0x00FF0000) >> 8 |
             (input & 0xFF000000) >> 24;

    return output;
}

/*
This function will return an integer with a reversed order of the byte representation of the input integer.

Example 1:
input: 0x12345678
return: 0x78563412

Example 2:
input: 0x01020304
return: 0x04030201 (==0x4030201, omitting the leading 0)

Example 3:
input: 0x01234567
return: 0x67452301
*/
int swap_bytes(int input)
{
    int output;

    byte_pointer in_ptr = (byte_pointer)&input;
    byte_pointer out_ptr = (byte_pointer)&output;

    for (size_t i = 0; i < sizeof(int); i++)
    {
        out_ptr[i] = in_ptr[sizeof(int) - 1 - i];
    }

    return output;
}

int main()
{
    // Declare variables to store user input
    int input;
    char inputFormat[10];

    // Infinite loop
    while (1)
    {
        // Prompt the user to enter an integer
        printf("Enter an integer (decimal or hexadecimal) [Enter '0' to exit]: ");

        // Read the input and its format
        if (scanf("%i", &input) == 1)
        {
            if (input == 0)
            {
                printf("Exiting the program.\n");
                break;
            }
            sprintf(inputFormat, "decimal");
        }
        else if (scanf("%x", &input) == 1)
        {
            if (input == 0)
            {
                printf("Exiting the program.\n");
                break;
            }
            sprintf(inputFormat, "hexadecimal");
        }
        else
        {
            printf("Invalid input. Please enter a valid integer in decimal or hexadecimal format.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        uint32_t inputAsUint32 = (uint32_t)input;

        uint32_t reversed = reverseByteOrder(inputAsUint32);
    
        int output = swap_bytes(input);
        printf("Reversed Byte Representation of %s %i: %#010x\n", inputFormat, input, reversed);

    }

    return 0;
}
