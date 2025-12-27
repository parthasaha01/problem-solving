#include<stdio.h>
#include<string.h>
int main()
{
    int L, right, i;
    double sum;
    char str[10000];

    while(gets(str))
    {
        if(str[0] == '*')
            break;

        L = strlen(str);
        right=0;
        sum = 0.0;

        for(i=1; i<L; i++)
        {
            switch(str[i])
            {
                case 'W':
                    sum += 1.0;
                    break;
                case 'H':
                    sum += 0.5;
                    break;
                case 'Q':
                    sum += 0.25;
                    break;
                case 'E':
                    sum += 0.125;
                    break;
                case 'S':
                    sum += 0.0625;
                    break;
                case 'T':
                    sum += 0.03125;
                    break;
                case 'X':
                    sum += 0.015625;
                    break;
                default:
                    if(sum == 1.0)
                        ++right;
                    sum = 0.0;
                    break;

            }
        }

        printf("%d\n", right);
    }

    return 0;
}
