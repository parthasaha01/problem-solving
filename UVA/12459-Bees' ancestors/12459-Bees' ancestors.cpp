#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long N, a, b, c, i;

    while(scanf("%lld", &N) && N)
    {
        a=0;
        b=1;

        for(i=1; i<=N;  i++)
        {
            c=a+b;
            a=b;
            b=c;
        }

        printf("%lld\n", c);
    }

    return 0;
}
