#include<stdio.h>
int main()
{
    long int n,rem,sum=0;

    while(scanf("%ld",&n)==1 && n!=0)
    {
        do
        {
            sum=0;
            while(n!=0)
            {
                rem=n%10;
                sum+=rem;
                n=n/10;
            }
            n=sum;
        }while(sum/10 != 0);

        printf("%ld\n",sum);
    }

    return 0;
}
