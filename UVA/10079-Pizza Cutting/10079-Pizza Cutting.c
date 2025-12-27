#include<stdio.h>
int main()
{
    long int N,sum,i;

    while(scanf("%ld", &N)==1 && N >= 0)
    {
        sum=1;
        for(i=0; i <= N; i++)
        {
            sum += i;
        }
        printf("%ld\n",sum);
    }

    return 0;
}
