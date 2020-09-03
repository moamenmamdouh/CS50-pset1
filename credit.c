#include <stdio.h>
#include <cs50.h>

bool checksum(long number, int counter); //checksum function declaration

int main(void)
{
    long input = get_long("Number: ");
    long number = input; // number is input used for counter calculations
    int counter = 1; // variable for storing number of digits
    long startingnum = 1;  // starting is input used to get significant digits in credit cards
    string output = "None";

    // Looping on the number to determine number of digits
    while (number > 9)
    {
        number /= 10;
        counter++;
    }

    // American Express is the only card with 15 digits "1st condition"

    if (counter == 15)
    {
        startingnum = input;

        // Division loop to get the first two digits "Significant digits for american express"

        for (int i = 0; i < 13; i++)
        {
            startingnum /= 10;
        }

        // Checking significant digits "2nd condition"

        if (startingnum == 34 || startingnum == 37)
        {
            // checksum formula verification "3rd condition"

            if (checksum(input, counter) == true)
            {
                output = "AMEX";
            }

            else
            {
                output = "INVALID";
            }
        }

        else
        {
            output = "INVALID";
        }
    }

    // VISA is the only card with 13 digits "1st condition"

    else if (counter == 13)
    {

        // number after counter operations has the significant digit "2nd condition"

        if (number == 4)
        {
            // checksum formula verification "3rd condition"

            if (checksum(input, counter) == true)
            {
                output = "VISA";
            }

            else
            {
                output = "INVALID";
            }
        }

        else
        {
            output = "INVALID";
        }
    }

    // VISA and Mastercard with 16 digits "1st condition"

    else if (counter == 16)
    {
        startingnum = input;

        // Division loop to get the first two digits "Significant digits for Mastercard"

        for (int i = 0; i < 14; i++)
        {
            startingnum /= 10;
        }

        // number after counter operations has the significant digit "2nd condition"

        if (number == 4)
        {
            // checksum formula verification "3rd condition"

            if (checksum(input, counter) == true)
            {
                output = "VISA";
            }

            else
            {
                output = "INVALID";
            }
        }


        // Checking significant digits "2nd condition"

        else if (startingnum == 51 || startingnum == 52 || startingnum == 53 || startingnum == 54 || startingnum == 55)
        {
            // checksum formula verification "3rd condition"

            if (checksum(input, counter) == true)
            {
                output = "MASTERCARD";
            }

            else
            {
                output = "INVALID";
            }
        }

        else
        {
            output = "INVALID";
        }
    }

    else
    {
        output = "INVALID";
    }

    printf("%s\n", output); //printing final output for the card type
}


// checksum function for credit cards numbers implementation

bool checksum(long number, int counter)
{
    int sum = 0;
    int factor = 1;

    for (int i = 0; i < counter; i++)
    {
        int digitsum = (number % 10) * factor;

        if (digitsum > 9)
        {
            digitsum = (digitsum / 10) + (digitsum % 10);
        }

        sum += digitsum;
        number /= 10;

        if (factor == 1)
        {
            factor = 2;
        }

        else
        {
            factor = 1;
        }
    }

    if (sum % 10 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }

}
