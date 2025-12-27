#include<stdio.h>
int main()
{
    long int T,a,b,c,x,y,z,i;

    scanf("%ld",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%ld %ld %ld",&a,&b,&c);
        if(a>b && a>c)
        {
            z=a;
            x=b;
            y=c;
        }
        else if(b>a && b>c)
        {
            z=b;
            x=a;
            y=c;
        }
        else
        {
            z=c;
            x=a;
            y=b;
        }

        if(z >= (x+y))
        {
            printf("Case %ld: Invalid\n",i);
        }
        else
        {
            if(x == y && x == z)
            {
                printf("Case %ld: Equilateral\n",i);
            }
            else if(x==y || y==z || z==x )
            {
                printf("Case %ld: Isosceles\n",i);
            }
            else
            {
                printf("Case %ld: Scalene\n",i);
            }
        }
    }

    return 0;
}
