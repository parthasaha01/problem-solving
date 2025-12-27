#include<stdio.h>
#include<string.h>
int main()
{
    char s[201];
    int i, find, Sum, L;

    while(gets(s))
    {
        if(s[0] == '*')
            break;

        find = Sum = 0;

        L = strlen(s);

        for(i = 1; i<L; i++)
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
                default:
                    if(Sum == 1000000)
                        find++;
                    Sum=0;
                    break;
            }

        }
        printf("%d\n", find);
    }
    return 0;
}
