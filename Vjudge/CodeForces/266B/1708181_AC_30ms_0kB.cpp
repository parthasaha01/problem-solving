#include<stdio.h>
#include<string.h>
int main()
{
    long int n, t, i;

    char str[10000];

    while(scanf("%ld %ld", &n, &t) == 2)
    {
        getchar();

        for(i=0; i<n; i++)
            scanf("%c", &str[i]);

        str[n] = '\0';

        while(t--)
        {
            for(i=0; i<n-1; i++)
            {
                if(str[i] == 'B' && str[i+1] == 'G')
                {
                    str[i] = 'G';
                    str[i+1] = 'B';

                    ++i;
                }
            }

            str[n] = '\0';
        }

        printf("%s\n", str);
    }

    return 0;
}