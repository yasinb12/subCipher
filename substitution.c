#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define A_POS 65
#define SIZE 80

int char_index(string target, int c);
bool valid_key(char key[]);
bool duplicate_chars(char key[]);
bool all_alpha(char key[]);

int main(int argc, string argv[])
{

    char plaintext[SIZE];
    int ciphertext[SIZE] = {' '};
    int subkey_index;
    char ch;
    char key[SIZE];
    int plaintext_letter = 0;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    strcpy(key, argv[1]);
    if (valid_key(key) == false)
    {
        printf("Invalid Key\n");
        return 1;
    }
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("ciphertext: ");
    for (int i = 0; i < (strlen(plaintext) - 1); i++)
    {
        plaintext_letter = (int)toupper(plaintext[i]);
        subkey_index = plaintext_letter - A_POS;
        if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[subkey_index]);
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[subkey_index]);
        }
        else if (isalpha(plaintext[i]) == false)
        {
            ciphertext[i] = plaintext[i];
        }
        printf("%c", ciphertext[i]);
        subkey_index = 0;
    }
    printf("\n");
    return 0;
}

// checks key for duplicate characters in a given key
// returns true if a duplicate is found
bool duplicate_chars(char key[])
{
    int n = strlen(key);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (key[i] == key[j])
            {
                return true;
            }
        }
    }
    return false;
}

// checks if all characters in a key are alphabetical
// returns false if a non-alphabetical character is found
bool all_alpha(char key[])
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}

bool valid_key(char key[])
{
    if (strlen(key) != 26)
    {
        return false;
    }
    else
    {
        return (all_alpha(key) && !duplicate_chars(key));
    }
}
