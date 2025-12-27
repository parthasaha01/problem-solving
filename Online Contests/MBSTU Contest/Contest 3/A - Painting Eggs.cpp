#include<bits/stdc++.h>
using namespace std;
#define mx 1000005;
struct st1
{
    int id,p;
}a[mx],g[mx];
bool cmp(st1 x, st1 y)
{
    return x.p < y.p;
}

int main()
{
    int n,geta,getg,total;
    while(scanf("%d",&n)==1)
    {
        geta=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            a.id=i;
            a.p=x;
            b.i=i;
            b.p=y;
            geta+=x;
        }
        total = 1000*n;
        getg = total-geta;


    }
}

