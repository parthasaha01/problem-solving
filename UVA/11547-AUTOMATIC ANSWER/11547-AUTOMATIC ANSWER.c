#include<stdio.h>
int main()
{
    long int t,n,i,tens_column;

    scanf("%ld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%ld",&n);

        n=(n*567);
        n=(n/9);
        n=(n+7492);
        n=(n*235);
        n=(n/47);
        n=(n-498);

        tens_column=(n/10)%10;

        if(tens_column < 0)
        {
            tens_column = -tens_column;
        }
        printf("%ld\n",tens_column);
    }

    return 0;
}
