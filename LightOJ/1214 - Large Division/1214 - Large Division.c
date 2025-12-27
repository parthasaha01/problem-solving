#include<stdio.h>
#include<string.h>
int main()
{
    long int T, i, j, num, rem, b, length;
    char a[205];

    scanf("%ld", &T);

    for(i=1; i<=T; i++)
    {
        scanf("%s %ld", &a, &b);

        if(b < 0)
            b = -b;

        length = strlen(a);
        num=0;
        j=0;

        if(a[0] == '-')
            j=1;

        while(j<length)
        {
            num += a[j] - '0';

            rem = num % b;

            num = (rem*10);

            ++j;
        }

        if(rem == 0)
            printf("Case %ld: divisible\n", i);
        else
            printf("Case %ld: not divisible\n", i);

    }

    return 0;
}
