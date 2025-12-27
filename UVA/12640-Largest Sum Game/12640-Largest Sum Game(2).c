#include<stdio.h>
int main(void)
{
    char ch;
    int num, Max, sum, exit;

    while (1)
    {
        Max = sum = 0;

        while (1)
        {
            exit = scanf("%d%c", &num, &ch);

            if (exit == -1)
                return 0;

            sum += num;

            if (sum < 0)
                sum = 0;
            else
            {
                if(sum>Max)
                    Max=sum;
            }

            if (ch == '\n' || exit == 1)
            {
                printf("%d\n", Max);
                break;
            }
        }
    }

    return 0;
}

