#include<stdio.h>
int main()
{
    long int n,s,d,a,b,i;
    long double x;

    scanf("%ld", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%ld %ld",&s,&d);
        if(s<d)
        {
            printf("impossible\n");
        }
        else
        {
            x=(s+d)/2.0;
            if(x != (int)x)
            {
                printf("impossible\n");
            }
            else
            {
                a=x;
                b=s-a;
                printf("%ld %ld\n",a,b);
            }
        }
    }

    return 0;
}
