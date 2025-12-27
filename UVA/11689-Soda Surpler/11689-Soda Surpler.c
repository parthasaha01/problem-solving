#include<stdio.h>
int main()
{
    long int N,e,f,c,sum,emp,drink,i;

    scanf("%ld",&N);
    for(i=1; i<=N; i++)
    {
        scanf("%ld %ld %ld",&e,&f,&c);
        sum=0;
        emp=e+f;
        while(emp>=c)
        {
            drink=(emp)/c;
            sum += drink;
            emp=drink+(emp%c);
        }
        printf("%ld\n",sum);
    }

    return 0;
}
