#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc, string argv[])

{

// Check if user has input a single command line argument

    if (argc != 2)
    {
        printf("Error: Key must be single positive integer \n");
        return 1;
    }

// Check if single command line argument contains only digits

    else
    {
        int key_length = strlen(argv[1]);
        for (int i = 0 ; i < key_length ; i++)
        {
            if (isdigit(argv[1][i]) != 0)
            {
                continue;
            }
            else
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        }
    }

// Convert user input cipher key string of digits to integers

    int key = atoi(argv[1]);

// Prompt user for plaintext

    string plaintext = get_string("plaintext: ");

// Convert plaintext ASCII to alphabetical index, perform cipher with user's key and print ciphertext

    int plaintext_len = strlen(plaintext);

    printf("ciphertext: ");

    for (int j = 0 ; j < plaintext_len ; j++)
        if (isupper(plaintext[j]))
        {
            printf("%c", (((plaintext[j] - 65) + key) % 26) + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (((plaintext[j] - 97) + key) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    printf("\n");
}