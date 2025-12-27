#include<stdio.h>
int main()
{
    long int length, sum,a,b,i;

    while(scanf("%ld",&length)==1 && length != 0)
    {
        a=0;
        b=1;
        for(i=1; i <= length; i++)
        {
            sum = a+b;
            a=b;
            b=sum;
        }
        printf("%ld\n",sum);
    }

    return 0;
}
