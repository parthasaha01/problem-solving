#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    long long T, L, i, M, MB, R, Max, n, nb, r, Min;
    char str[100];

    scanf("%lld", &T);
    getchar();

    while(T--)
    {
        gets(str);
        L = strlen(str);

        R=1;
        M = MB = 0;

        n = 1;
        r = nb = 0;

        for(i=0; i<L; i++)
        {
            if( isdigit(str[i]) )
            {
                MB = (MB*10) + (str[i] - '0');

                nb = (nb*10) + (str[i] - '0');
            }
            else
            {
                if(str[i] == '*')
                {
                    R *= M+MB;
                    M = 0;

                    n *= nb;
                }
                else
                {
                    M += MB;

                    r += (n*nb);
                    n = 1;
                }

                MB = 0;
                nb = 0;
            }
        }

        Max = R* (M+MB);
        Min = r + (n*nb);

        printf("The maximum and minimum are %lld and %lld.\n", Max, Min);


    }

    return 0;
}
