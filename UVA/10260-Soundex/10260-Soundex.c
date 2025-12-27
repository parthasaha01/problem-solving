#include<stdio.h>
#include<string.h>
int main()
{
    int L, i, p, s;
    char str[25];

    while(gets(str))
    {
        L = strlen(str);
        s=0;

        for(i=0; i<L; i++)
        {
            if(str[i] == 'B' || str[i] == 'F' || str[i] == 'P' || str[i] == 'V')
            {
                if( s != 1)
                    printf("1");

                s=1;
            }
            else if(str[i] == 'C' || str[i] == 'G' || str[i] == 'J' || str[i] == 'K' || str[i] == 'Q' || str[i] == 'S' || str[i] == 'X' || str[i] == 'Z')
            {
                if(s != 2)
                    printf("2");

                s=2;
            }
            else if(str[i] == 'D' || str[i] == 'T')
            {
                if(s != 3)
                    printf("3");

                s=3;
            }
            else if(str[i] == 'L')
            {
                if(s != 4)
                    printf("4");

                s=4;
            }
            else if(str[i] == 'M' || str[i] == 'N')
            {
                if(s != 5)
                    printf("5");

                s=5;
            }
            else if(str[i] == 'R')
            {
                if(s != 6)
                    printf("6");

                s=6;
            }
            else
            {
                s=0;
            }
        }

        printf("\n");
    }

    return 0;
}
