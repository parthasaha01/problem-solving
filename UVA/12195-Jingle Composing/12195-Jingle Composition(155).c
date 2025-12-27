#include<stdio.h>
int main()
{
    char s[201];
    int i, find, Sum;

    while(gets(s))
    {
        if(s[0] == '*')
            break;

        find = Sum = 0;

        for(i = 1; i<201; i++)
        {
            switch(s[i])
            {
                case 'W':Sum += 1000000;break;
                case 'H':Sum +=  500000;break;
                case 'Q':Sum +=  250000;break;
                case 'E':Sum +=  125000;break;
                case 'S':Sum +=   62500;break;
                case 'T':Sum +=   31250;break;
                case 'X':Sum +=   15625;break;
                case '/':
                    if(Sum == 1000000)
                        find++;
                    Sum=0;
                    break;
                default:
                    goto line;
            }

        }

        line:
        printf("%d\n", find);
    }
    return 0;
}
