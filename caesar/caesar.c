#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_cipher(string s, int keyP);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("USAGE: ./caesar key\n");
        return 1;
    }

    bool statement = true;
    for (int j = 0; j < strlen(argv[1]); j++)
    {
        if (!isdigit(argv[1][j]))
        {
            statement = false;
            printf("USAGE: ./caesar key\n");
            return 1;
        }
    }

    if (statement)
    {
        int key = atoi(argv[1]);
        if (key < 0)
        {
            printf("USAGE: ./caesar key\n");
            return 1;
        }

        string plaintext = get_string("plaintext: ");
        get_cipher(plaintext, key);
        printf("ciphertext: %s\n", plaintext);
    }
}

void get_cipher(string s, int key)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (isupper(s[i]))
        {
            s[i] = (((s[i]) - 'A' + key) % 26) + 'A';
        }
        else if (islower(s[i]))
        {
            s[i] = (((s[i]) - 'a' + key) % 26) + 'a';
        }
    }
}
