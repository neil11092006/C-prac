#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnumber = get_long("Enter card number: ");
    int sum = 0;
    int position = 0;
    long card = cardnumber;

    while (card > 0)
    {
        int digit = card % 10;

        if (position % 2 == 1)
        {
            int product = digit * 2;
            sum += product / 10 + product % 10;
        }
        else
        {
            sum += digit;
        }
        card = card / 10;
        position++;
    }

    if (sum % 10 == 0)
    {

        long start = cardnumber;
        while (start >= 100)
        {
            start /= 10;
        }

        if ((start == 34 || start == 37) && position == 15)
        {
            printf("AMEX\n");
        }
        else if ((start >= 51 && start <= 55) && position == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (start / 10 == 4 && (position == 13 || position == 16))
        {
            printf("VISA\n");
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
