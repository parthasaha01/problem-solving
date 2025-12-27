#include<stdio.h>
int main()
{
    long int n,rem,sum;

    while(scanf("%ld",&n)==1 && n!=0)
    {
        sum=12;
        while(sum/10 != 0)
        {
            sum=0;
            while(n!=0)
            {
                rem=n%10;
                sum+=rem;
                n=n/10;
            }
            n=sum;
        }
        printf("%ld\n",sum);
    }

    return 0;
}
