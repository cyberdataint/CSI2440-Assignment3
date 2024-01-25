#include <stdio.h>
#include <stdlib.h>


typedef unsigned char *byte_pointer;


int swap_bytes(int input)
{
    // Declare an integer variable to store the result
    int output;
    
    // Declare byte pointers to point to the input and output integers
    byte_pointer in_ptr = (byte_pointer)&input;
    byte_pointer out_ptr = (byte_pointer)&output;

    // Iterate through each byte of the input and update the output with reversed order
    for (size_t i = 0; i < sizeof(int); i++)
    {
        out_ptr[i] = in_ptr[sizeof(int) - 1 - i];
    }

    // Return the result with reversed byte order
    return output;
}

// Main function
int main()
{
    // Declare an integer variable to store user input
    int input;

    // Infinite loop to repeatedly ask the user for input
    while (1)
    {
        // Prompt the user to enter an integer (0 to exit)
        printf("Enter an integer (0 to exit): ");
        
        // Read an integer in hexadecimal format from the user
        if (scanf("%x", &input) == 1)
        {
            // Check if the entered integer is 0 to exit the loop
            if (input == 0)
            {
                break;
            }

            // Call the swap_bytes function to get the reversed byte representation
            int output = swap_bytes(input);
            
            // Print the reversed byte representation in hexadecimal format
            printf("Reversed Byte Representation: %#lx\n", output);
        }
        else
        {
            // Display an error message for invalid input and clear the input buffer
            printf("Invalid input. Please enter a valid integer in hexadecimal format.\n");
            while (getchar() != '\n');
        }
    }

    return 0;
}
