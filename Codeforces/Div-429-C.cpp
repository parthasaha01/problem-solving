#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200005
int m,n,a[mx+5],b[mx+5];
struct data
{
    int v,id,r;
}st[mx+5];
bool cmpa(int x,int y)
{
    return x>y;
}
bool cmpb(data x,data y)
{
    return x.v<y.v;
}
bool cmpc(data x,data y)
{
    return x.id<y.id;
}

int main()
{
    while(scanf("%I64d",&m)==1)
    {
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&b[i]);
            st[i].v=b[i];
            st[i].id=i;
        }

        sort(a+1,a+m+1,cmpa);
        sort(st+1,st+m+1,cmpb);

        for(int i=1; i<=m; i++)
        {
            st[i].r = a[i];
        }

        sort(st+1,st+m+1,cmpc);

        for(int i=1; i<=m; i++)
        {
            if(i==m)printf("%d\n",st[i].r);
            else printf("%d ",st[i].r);
        }
    }

    return 0;
}

