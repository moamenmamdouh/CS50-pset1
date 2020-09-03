#include <stdio.h>
#include <cs50.h>

int main()
{
    int height;
    // asks user for pyramid height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // handles wrong inputs

    for (int i = 0; i < height; i++)  // Drawing rows
    {
        for (int j = 0; j < (height - (i + 1)); j++)  // Drawing left side spaces
        {
            printf(" ");
        }

        for (int k = 0; k < (i + 1); k++) // Drawing left side hashes
        {
            printf("#");
        }

        for (int j = 0; j < 2; j++)
        {
            printf(" "); // Drawing middle space
        }

        for (int k = 0; k < (i + 1); k++) // Drawing right side hashes
        {
            printf("#");
        }

        printf("\n"); // getting from one row to the other
    }

}
