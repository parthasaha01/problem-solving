#include<stdio.h>
#include<string.h>
int main()
{
    long int N, i, L, T, rem, num;
    char P[2005];

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &N);
        getchar();
        gets(P);

        L = strlen(P);
        num = 0;

        for(i=0; i<L; i++)
        {
            num += P[i] - 48;
            rem = num%N;
            num = rem*10;

        }

        printf("%ld\n", rem);
    }

    return 0;
}
