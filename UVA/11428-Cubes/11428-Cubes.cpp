#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int x, y;
int cubes(long long N)
{

    for(x=1; x<60; x++)
    {
        for(y=0; y<x; y++)
        {
            if(N == (x*x*x - y*y*y))
                return 1;
        }
    }

    return 0;
}
int main()
{
    long long N, result;

    while(scanf("%lld", &N) && N)
    {
        result = cubes(N);

        if(result)
            printf("%d %d\n", x, y);
        else
            printf("No solution\n");
    }

    return 0;
}
