#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_score(string word);

int POINTS[]=
    {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
    5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
    1, 4, 4, 8, 4, 10
    };


int main(void)
{

    string answer1 = get_string("Player1: ");
    int score1 = get_score(answer1);
    string answer2 = get_string("Player2: ");
    int score2 = get_score(answer2);

    if(score1 > score2)
    {
        printf("Player 1 wins! \n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}


int get_score(string word)
{
    int score=0;
    int n = strlen(word);
    for(int i = 0; i < n; i++)
    {
       if(toupper(word[i]) >= 'A' && toupper(word[i]) <= 'Z')
       {
        int index = toupper(word[i]) - 'A';
        score += POINTS[index];
       }
    }
    return score;
}
