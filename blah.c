#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

float get_grade(string s);

int main(void)
{
    string text = get_string("Text: ");
    int grade = get_grade(text);
    printf("Grade %i\n", grade );
}

float get_grade(string s)
{
    int letters = 0;
    int words = 0;
    int sent = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if(s[i] != ' ')
        {
            letters++;
        }

        if(s[i] == ' ')
        {
            words++;
        }
        if(s[i] == '.' || s[i] == ';')
        {
            sent++;
        }
    }
    float L = (letters / words) * 100;
    float S = (sent / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}