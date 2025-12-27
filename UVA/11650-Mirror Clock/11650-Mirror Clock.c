#include<stdio.h>
int main()
{
    long int T, H, M, i;
    char ch;

    scanf("%ld", &T);

    for(i=1; i<=T; i++)
    {

        scanf("%ld %c %ld", &H, &ch, &M);

        if(H == 12)
        {
            if(M == 0)
                printf("12:00\n");

            else
            {
                H=11;
                M=60-M;

                if(M<10)
                    printf("%ld:0%ld\n", H, M);
                else
                    printf("%ld:%ld\n", H, M);
            }
        }

        else
        {
            if(H>12)
                H = H-12;

            if(M == 0)
            {
                H=12-H;

                if(H<10)
                    printf("0%ld:00\n", H);
                else
                    printf("%ld:00\n", H);
            }
            else
            {
                H=11-H;
                M=60-M;

                if(H==0)
                    H=12;

                if(H<10 && M<10)
                    printf("0%ld:0%ld\n", H, M);

                else if(H<10 && M>=10)
                    printf("0%ld:%ld\n", H, M);

                else if(H>=10 && M<10)
                    printf("%ld:0%ld\n", H, M);

                else
                    printf("%ld:%ld\n", H, M);
            }
        }

    }

    return 0;
}
