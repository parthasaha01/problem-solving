#include<bits/stdc++.h>
using namespace std;
long long int xx[1005],yy[1005];
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    if(a>b)swap(a,b);

    long long int cur = 0;
    xx[a-1]=0;
    for(int i=a; i<=b; i++)
    {
        xx[i] = xx[i-1] + cur;
        cur++;
    }

    yy[b+1] = 0;
    cur = 0;
    for(int i=b; i>=a; i--)
    {
        yy[i] = yy[i+1] + cur;
        cur++;
    }

    long long ans = 1000000000000000;

    for(int i=a; i<=b; i++)
    {
        long long int r = xx[i]+yy[i];
        ans = min(ans,r);
    }

    printf("%I64d\n",ans);

    return 0;
}
