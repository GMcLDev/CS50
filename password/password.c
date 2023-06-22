// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int length = strlen(password);

    bool lowercase = false;
    bool uppercase = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0 ; i < length; i++)
    {
        // printf("password[i]: %c\n", password[i]);
        // printf("uppercase %d\n", uppercase);
        // printf("lowercase %d\n", lowercase);
        // printf("number %d\n", number);
        // printf("symbol %d\n", symbol);

        if(uppercase == false)
        {
            if (isupper(password[i]))
            {
                uppercase = true;
                // printf("Got uppercase %c\n", password[i]);
                // printf("if uppercase %d\n", uppercase);
            }
        }
        if (lowercase == false)
        {
            if (islower(password[i]))
            {
                lowercase = true;
                // printf("Got lowercase %c\n", password[i]);
                // printf("if lowercase %d\n", lowercase);
            }
        }

        if (number == false)
        {
            if (isdigit(password[i]))
            {
                number = true;
                // printf("Got digit %c\n", password[i]);
                // printf("if number %d\n", number);
            }
        }
        if (symbol == false)
        {
            if(!isalnum(password[i]))
            {
                symbol = true;
                // printf("Got symbol %c\n", password[i]);
                // printf("if symbol %d\n", symbol);
            }
        }
    }

    if(lowercase == false || uppercase == false || number == false || symbol == false)
    {
        // printf("invalid\n");
        return false;
    }
        else
            {
                // printf("valid\n");
                return true;
            }

    return 0;
}

