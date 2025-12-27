#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,n;

    while(scanf("%lld %lld %lld",&a,&b,&n))
    {
        if(a+b+n==0)
            break;
        n%=5;
        switch(n)
        {
            case 0:
                printf("%lld\n",a);
                break;
            case 1:
                printf("%lld\n",b);
                break;
            case 2:
                printf("%lld\n",(b+1)/a);
                break;
            case 3:
                printf("%lld\n",(a+b+1)/(a*b));
                break;
            default:
                printf("%lld\n",(a+1)/b);
                break;
        }
    }

    return 0;
}
