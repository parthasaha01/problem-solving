#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long S, D, mem, day;

    while(scanf("%lld %lld", &S, &D)==2)
    {
       mem=day=S;

        while(day<D)
        {
            day += (++S);
            mem++;
        }

        printf("%lld\n", mem);
    }

    return 0;
}
