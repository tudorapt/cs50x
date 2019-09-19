#include <stdio.h>
#include <cs50.h>

// Count the number of digits
int digits(long number)
{
    int count = 0;

    while (number != 0)
    {
        number /= 10;
        count++;
    }

    return count;
}

// Get first n digits of a number
long firstdig(long number, int n)
{
    long dig = number;

    for (int i = 0; i < (digits(number) - n); i++)
    {
        dig /= 10;
    }

    return dig;
}

// Sum of the product digits
int l_sumone(long number)
{
    int sum = 0;
    int prod = 0;

    number = number / 10;

    while (number != 0)
    {
        prod = (number % 10) * 2;

        if (prod > 9)
        {
            prod = (prod / 10) + (prod % 10);
        }

        sum += prod;
        number /= 100;
    }

    return sum;
}

// Sum of the digits that were not multiplied
int l_sumtwo(long number)
{
    int sum = 0;

    while (number != 0)
    {
        sum += number % 10;
        number /= 100;
    }

    return sum;
}

int luhn(long number)
{

    if ((l_sumone(number) + l_sumtwo(number)) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    long number = 0;
    int dig = 0;

    number = get_long("Number: ");

    dig = digits(number);

    if (luhn(number) == 1)
    {
        if (dig == 13)
        {
            if (firstdig(number, 1) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (dig == 15)
        {
            if (firstdig(number, 2) == 34 || firstdig(number, 2) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (dig == 16)
        {
            if (firstdig(number, 1) == 4)
            {
                printf("VISA\n");
            }
            else if (firstdig(number, 2) >= 51 && firstdig(number, 2) <= 55)
            {
                printf("MASTERCARD\n");
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