#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int distance(int N);
int main()
{
    int N, result;

    while(scanf("%d", &N)==1 && N != 0)
    {
        result=distance(N);

        if(result == 1)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }

    return 0;
}
int distance(int N)
{
    int ara[N], i, diff;

    for(i=0; i<N; i++)
        scanf("%d", &ara[i]);

    sort(ara, ara+N);

    if(ara[0] > 200)
        return 0;

    diff =1422 - ara[N-1];

    if(diff > 100)
        return 0;

    for(i=0; i<N-1; i++)
    {
        diff = ara[i+1]-ara[i];
        if(diff > 200)
            return 0;
    }

    return 1;
}
