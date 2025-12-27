#include<stdio.h>
int main()
{
    int N, i, ara[5], k, p;
    char str[] = "ABCDE";

    while(scanf("%d", &N) && N)
    {
        while(N--)
        {
            p=0;

            for(i=0; i<5; i++)
            {
                scanf("%d", &ara[i]);

                if(ara[i]<128)
                {
                    ++p;
                    k=i;
                }
            }

            if(p==1)
                printf("%c\n", str[k]);
            else
                printf("*\n");
        }
    }

    return 0;
}
