#include<bits/stdc++.h>
using namespace std;
#define Mx 100005
struct dt
{
    int mn,mx;
}st[Mx+5][20];
int a[Mx+5];
void createSparsetable(int n)
{
    for(int i=1; i<=n; i++)
    {
        st[i][0].mn=i;
        st[i][0].mx=i;
    }

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            int x,y;

            x=st[i][j-1].mn;
            y=st[i+(1<<(j-1))][j-1].mn;
            if(a[x]<=a[y]) st[i][j].mn=x;
            else st[i][j].mn=y;

            x=st[i][j-1].mx;
            y=st[i+(1<<(j-1))][j-1].mx;
            if(a[x]>=a[y])st[i][j].mx=x;
            else st[i][j].mx=y;
        }
    }
}
int solve(int b,int e)
{
    dt ans;
    int x,y,k;
    k=(int)log2(e-b+1);

    x=st[b][k].mn;
    y=st[e-(1<<k)+1][k].mn;
    ans.mn=min(a[x],a[y]);

    x=st[b][k].mx;
    y=st[e-(1<<k)+1][k].mx;
    ans.mx=max(a[x],a[y]);

    return ans.mx-ans.mn;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n,d;
        scanf("%d%d",&n,&d);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        createSparsetable(n);
        int maxx=0;
        for(int i=1; i<=n-d+1; i++)
        {
            maxx=max(maxx,solve(i,i+d-1));
        }

        printf("Case %d: %d\n",ks,maxx);
    }

    return 0;
}
