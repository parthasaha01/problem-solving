#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int answer(long N, long M);
int main()
{
    long int N, M, result;

    while(scanf("%ld %ld", &N, &M) == 2)
    {
            result = answer(N, M);

        if(result == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
int answer(long N, long M)
{
    long int ara[M];
    long int i, j, p, ans;

    if(M == 0)
        return 1;

    for(i=0; i<M; i++)
    {
        scanf("%ld", &ara[i]);
    }

    sort(ara, ara+M);

    if(ara[0] == 1 || ara[M-1] == N)
        return 0;

    ans = 0;

    for(j=0; j <M-2; j++)
    {
        p = ara[j+2] - ara[j];

        if(p == 2)
        {
            return 0;
        }
    }

    return 1;

}