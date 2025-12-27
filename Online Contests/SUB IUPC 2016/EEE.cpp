#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define one (2<<31)-1
int AND[4*mx],OR[4*mx],XOR[4*mx],a[mx];
void init_AND(int nd,int b,int e)
{
    if(b==e){AND[nd] = a[b]; return;}

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    init_AND(lf,b,md);
    init_AND(rg,md+1,e);

    AND[nd] = AND[lf] & AND[rg];
}
void init_OR(int nd,int b,int e)
{
    if(b==e){OR[nd] = a[b]; return;}

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    init_OR(lf,b,md);
    init_OR(rg,md+1,e);

    OR[nd] = OR[lf] | OR[rg];
}
void init_XOR(int nd,int b,int e)
{
    if(b==e){XOR[nd] = a[b]; return;}

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    init_XOR(lf,b,md);
    init_XOR(rg,md+1,e);

    XOR[nd] = XOR[lf] ^ XOR[rg];
}
int query_AND(int nd,int b,int e,int x,int y)
{
    if(e<x || b>y)return one;

    if(b>=x && e<=y)return AND[nd];

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    int ad1 = query_AND(lf,b,md,x,y);
    int ad2 = query_AND(rg,md+1,e,x,y);

    return ad1 & ad2;
}
int query_OR(int nd,int b,int e,int x,int y)
{
    if(e<x || b>y)return 0;

    if(b>=x && e<=y)return OR[nd];

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    int or1 = query_OR(lf,b,md,x,y);
    int or2 = query_OR(rg,md+1,e,x,y);

    return or1 | or2;
}
int query_XOR(int nd,int b,int e,int x,int y)
{
    if(e<x || b>y)return 0;

    if(b>=x && e<=y)return XOR[nd];

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    int xr1 = query_XOR(lf,b,md,x,y);
    int xr2 = query_XOR(rg,md+1,e,x,y);

    return xr1 ^ xr2;
}
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    init_AND(1,1,n);
    init_OR(1,1,n);
    init_XOR(1,1,n);

    int qq; scanf("%d",&qq);

    for(int i=1; i<=qq; i++)
    {
        char ss[10];
        int x,y; scanf("%d %s %d",&x,&ss,&y);

        int ans=0;

        if(ss[0]=='A'){
            ans = query_AND(1,1,n,x,y);
        }
        else if(ss[0]=='O'){
            ans = query_OR(1,1,n,x,y);
        }
        else{
            ans = query_XOR(1,1,n,x,y);
        }

        printf("%d\n",ans);
    }
    return 0;
}
