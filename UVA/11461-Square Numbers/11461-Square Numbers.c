#include<stdio.h>
#include<math.h>
int main()
{
    long long a,b,r;
    double sqr;
    while(scanf("%lld %lld",&a,&b)==2 && (a!=0 || b!=0))
    {
        r=0;
        while(a<=b)
        {
            sqr=sqrt(a);
            if(sqr == (int)sqr)
            {
                r++;
            }
            a++;
        }
        printf("%lld\n",r);
    }

    return 0;
}
