#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long test=1, B, S;

    while(scanf("%lld %lld", &B, &S))
    {
        if(!B && !S)
            break;

        if(B==1)
            printf("Case %lld: :-\\\n", test++);
        else if(B > S)
            printf("Case %lld: :-(\n", test++);
        else
            printf("Case %lld: :-|\n", test++);
    }

    return 0;
}
