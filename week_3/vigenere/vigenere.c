#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int checkinput(char *s);
char *rotate(char *s, char *key);

int main(int argc, char *argv[])
{

    // Check argument count
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword");
        return 1;
    }

    // Checks input to be only chars from a-Z with no numbers
    if (checkinput(argv[1]) == 1)
    {
        printf("Usage: ./vigenere keyword");
        return 1;
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
        printf("ciphertext: %s\n", rotate(plaintext, argv[1]));
    }

    return 0;
}

// Checks input to be only chars from a-Z with no numbers
int checkinput(char *s)
{
    int i = 0;

    while (s[i])
    {
        if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
        {
            i++;
        }
        // Bad input char
        else
        {
            return 1;
        }
    }
    return 0;
}

// Main cipher function
char *rotate(char *s, char *key)
{
    int i = 0;
    int j = 0;
    int keylen = strlen(key);

    // Convert all key chars to uppercase
    for (int k = 0; key[k]; k++)
    {
        if (key[k] > 96)
        {
            key[k] = key[k] - 32;
        }
    }

    while (s[i]) 
    {
        if (s[i] > 64 && s[i] < 91)
        {
            s[i] = 65 + (((s[i] - 65) + (key[j % keylen] - 65)) % 26);
            j++;    
        }
        else if (s[i] > 96 && s[i] < 123)
        {
            s[i] = 97 + (((s[i] - 97) + (key[j % keylen] - 65)) % 26);
            j++;
        }
        i++;
    }
    return s;
}