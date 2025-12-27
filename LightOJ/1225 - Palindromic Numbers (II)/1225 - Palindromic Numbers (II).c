#include<stdio.h>
int main()
{
    long int T, n, rem, num, rev, i;

    scanf("%ld", &T);

    for(i=1; i <= T; i++)
    {
        scanf("%ld", &n);

        num = n;
        rev = 0;

        while(num != 0)
        {
            rem = num%10;

            rev = (rev*10)+rem;

            num = num/10;
        }

        if(rev == n)
            printf("Case %ld: Yes\n", i);
        else
            printf("Case %ld: No\n", i);
    }

    return 0;
}
