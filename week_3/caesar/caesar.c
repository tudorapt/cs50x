#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

int checkinput(char *s);
char *rotate(char *s, int key);

int main(int argc, char *argv[])
{
    int cipher = 0;

    // Check argument count
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    // Check for non-numbers in key argument
    if (checkinput(argv[1]) == 1)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else
    {
        cipher = atoi(argv[1]);
    }

    // Input plaintext
    char *plaintext = get_string("plaintext:  ");

    // Make sure string is read
    if (plaintext == NULL)
    {
        return 1;
    }
    else
    {
        printf("ciphertext: %s\n", rotate(plaintext, cipher));
    }

    return 0;
}

// Checks input to be only chars from 0 to 9
int checkinput(char *s)
{
    while (*s)
    {
        if (*s < 48 || *s > 57)
        {
            return 1;
        }
        s++;
    }
    return 0;
}

// Main cypher function
char *rotate(char *s, int key)
{
    int i = 0;

    while (s[i]) 
    {
        if (s[i] > 64 && s[i] < 91)
        {
            s[i] = 65 + ((s[i] - 65 + key) % 26);
        }
        else if (s[i] > 96 && s[i] < 123)
        {
            s[i] = 97 + ((s[i] - 97 + key) % 26);
        }
        i++;
    }
    return s;
}