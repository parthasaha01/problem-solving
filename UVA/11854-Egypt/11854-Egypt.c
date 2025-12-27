#include<stdio.h>
int main()
{
    long int a,b,c,x,y,M,p,q;
    while(scanf("%ld %ld %ld", &a,&b,&c)==3 && a!=0 && b!=0 && c!=0) /* we can also wrire &&( a!=0 || b!=0 || c!=0 )   */
    {
        if(a>b && a>c)
        {
            M=a;
            p=b;
            q=c;
        }
        else if(b>a && b>c)
        {
            M=b;
            p=a;
            q=c;
        }
        else
        {
            M=c;
            p=a;
            q=b;
        }
        x=(p*p)+(q*q);
        y=(M*M);

        if(x==y)
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }

    return 0;
}
