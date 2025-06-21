#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_grade(string s);

int main(void)
{
    string text = get_string("Text: ");
    int grade = get_grade(text);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int get_grade(string s)
{
    int letters = 0;
    int words = 1;
    int sent = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            if (isalpha(s[i]))
            {
                letters++;
            }
            else if (s[i] == '.' || s[i] == '?' || s[i] == '!')
            {
                sent++;
            }
        }

        if (s[i] == ' ')
        {
            words++;
        }
    }
    float L = ((float) letters / words) * 100;
    float S = ((float) sent / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}
