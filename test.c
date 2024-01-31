#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;


int swap_bytes(int input)
{
  int output;
  byte_pointer p = (byte_pointer)&input;
  byte_pointer q = (byte_pointer)&output;

  for (int i = 0; i < 4; i++)
  {
    *(q + i) = *(p + 3 - i);
  }

  return output;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <integer>\n", argv[0]);
    return 1;
  }

  int input = (int)strtol(argv[1], NULL, 0);
  int output = swap_bytes(input);

  printf("Reversed Byte Representation: %#010x\n", output);
  
  return 0;
}