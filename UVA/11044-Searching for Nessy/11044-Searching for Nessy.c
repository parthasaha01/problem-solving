#include<stdio.h>
int main()
{
    long int n,m,i,x,y,t,sum;

    scanf("%ld",&t);
    for(i=1; i<=t; i++)
    {
        sum=0;
        scanf("%ld %ld",&n,&m);
        if(m >= 3)
        {
            x=(n/3)*3;
            y=(m/3)*3;
            sum=(x*y)/9;
        }
        printf("%ld\n",sum);
    }

    return 0;
}
