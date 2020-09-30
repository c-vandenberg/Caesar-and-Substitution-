#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

bool validate(char *s);

int main(int argc, char *argv[])

{
// Check if user has input a single command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    char *key = argv[1];
    if (validate(key) != 0)
    {
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        int plaintext_len = strlen(plaintext);
        // Encipher plaintext
        char output[plaintext_len];
        for (int k = 0; k < plaintext_len ; k++)
        {
            if (islower(plaintext[k]))
            {
                output[k] = tolower(key[plaintext[k] - 97]);
            }
            else if (isupper(plaintext[k]))
            {
                output[k] = toupper(key[plaintext[k] - 65]);
            }
            else
            {
                output[k] = plaintext[k];
            }
        }
        output[plaintext_len] = '\0';
        // Print output and end program
        printf("ciphertext: %s\n", output);
        return 0;
    }
}

// Function to validate key
bool validate(char *s)

{
    // Convert key to lowercase
    int key_length = strlen(s);
    char lowercase_key [26];
    for (int i = 0 ; i < key_length ; i++)
    {
        lowercase_key[i] = tolower(s[i]);
    }
    int counter = 0;
    for (int i = 0 ; i < key_length ; i++)
    {
        for (int j = 0 ; lowercase_key[j] != '\0' ; j++)
        // Identify number of repeated characters (if any)
        {
            if (lowercase_key[j] == lowercase_key[i])
            {
                counter++;
            }
        }
        // Check whether key is 26 characters long and contains only alphabetic characters
        if ((key_length != 26) || (isalpha(s[i]) == 0))
        {
            printf("Error: Key must contain all 26 alphabetic characters and no other characters \n");
            return 1;
        }
    }
    // Check if there are any repeated characters
    if (counter != key_length)
    {
        printf("Error: Key must contain all 26 alphabetic characters and no other characters \n");
        return 1;
    }
    return 0;
}


