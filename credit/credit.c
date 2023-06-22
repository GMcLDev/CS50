#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // initialize cardNumber and array
    long cardNumber;
    long cardNumberArray[16];

    // get cardNumber
    cardNumber = get_long("Number:\n");

    // initialize cardArrayIndex and modulus
    int cardArrayIndex = 0;
    long lastDigit;

    // gets every last digit from cardNumber and adds it to cardNumberArray
    while (cardNumber > 0)
    {
        lastDigit = cardNumber % 10; // last digit
        cardNumber = cardNumber / 10;  // remove last digit
        cardNumberArray[cardArrayIndex] = lastDigit; // add lastDigit to cardNumberArray
        cardArrayIndex++; // tracks index to push lastDigit to cardArrayIndex
    }

    // Luhn's Algorithm

    // initialize variables to complete algorithm
    int oddNumbs = 0;
    int evenNumbs = 0;

// Checks card number is correct length and calculates Luhn's then type or print invalid
    if (cardArrayIndex == 13 || cardArrayIndex == 14 || cardArrayIndex == 15 || cardArrayIndex == 16)
    {
        for (int i = 0; i < cardArrayIndex; i++)
        {
            if (i % 2 == 0)
            {
                evenNumbs += cardNumberArray[i];
            }
            else
            {
                int doubleDigit = cardNumberArray[i] * 2;
                while (doubleDigit > 0)
                {
                    int digit = doubleDigit % 10; // last digit of odd indexed numbers
                    doubleDigit = doubleDigit / 10; // reduce until no digits > 0
                    oddNumbs += digit; // add last digit to oddNumbs
                }
            }
        }

        long luhnsNumber = oddNumbs + evenNumbs;
        // printf("%ld", luhnsNumber);

        if (luhnsNumber % 10 == 0)
        {
            if (cardNumberArray[cardArrayIndex - 1] == 3 && cardNumberArray[cardArrayIndex - 2] == 4)
            {
                printf("AMEX\n");
            }
            else if (cardNumberArray[cardArrayIndex - 1] == 3 && cardNumberArray[cardArrayIndex - 2] == 7)
            {
                printf("AMEX\n");
            }
            else if (cardNumberArray[cardArrayIndex - 1] == 5 && cardNumberArray[cardArrayIndex - 2] == 1)
            {
                printf("MASTERCARD\n");
            }
            else if (cardNumberArray[cardArrayIndex - 1] == 5 && cardNumberArray[cardArrayIndex - 2] == 2)
            {
                printf("MASTERCARD\n");
            }
            else if (cardNumberArray[cardArrayIndex - 1] == 5 && cardNumberArray[cardArrayIndex - 2] == 3)
            {
                printf("MASTERCARD\n");
            }
            else if (cardNumberArray[cardArrayIndex - 1] == 5 && cardNumberArray[cardArrayIndex - 2] == 4)
            {
                printf("MASTERCARD\n");
            }
            else if (cardNumberArray[cardArrayIndex - 1] == 5 && cardNumberArray[cardArrayIndex - 2] == 5)
            {
                printf("MASTERCARD\n");
            }
            else if (cardNumberArray[cardArrayIndex - 1] == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}