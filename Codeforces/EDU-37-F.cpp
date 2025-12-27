#include<bits/stdc++.h>
using namespace std;
#define mx 300005
#define ll long long
int a[mx+5],Div[1000005];
ll sum[mx*4],maxx[mx*4];
void init(int nd,int b,int e)
{
    if(b==e){
        sum[nd] = maxx[nd] = a[b];
        return;
    }
    int lf=2*nd; int rg=2*nd+1; int md=(b+e)/2;
    init(lf,b,md);
    init(rg,md+1,e);
    sum[nd] = sum[lf]+sum[rg];
    maxx[nd] = max(maxx[lf],maxx[rg]);
}
void update(int nd,int b,int e,int x,int y)
{
    if(maxx[nd]<=2)return;

    if(b==e){
        sum[nd] = maxx[nd] = Div[sum[nd]];
        return;
    }

    int lf=2*nd; int rg=2*nd+1; int md=(b+e)/2;

    if(y<=md)update(lf,b,md,x,y);
    else if(x>md) update(rg,md+1,e,x,y);
    else{
        update(lf,b,md,x,md);
        update(rg,md+1,e,md+1,y);
    }
    sum[nd] = sum[lf]+sum[rg];
    maxx[nd] = max(maxx[lf],maxx[rg]);
}
ll query(int nd,int b,int e,int x,int y)
{
    if(b==x&&e==y)return sum[nd];

    int lf=2*nd; int rg=2*nd+1; int md=(b+e)/2;

    if(y<=md)return query(lf,b,md,x,y);
    else if(x>md) return query(rg,md+1,e,x,y);
    else{
        ll p1 = query(lf,b,md,x,md);
        ll p2 = query(rg,md+1,e,md+1,y);
        return p1+p2;
    }
}
int main()
{
    for(int i=1; i<=1000000; i++){
        for(int j=i; j<=1000000; j+=i){
            Div[j]++;
        }
    }

    int n,m; scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    init(1,1,n);

    while(m--)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1){
            update(1,1,n,l,r);
        }
        else{
            ll ans = query(1,1,n,l,r);
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
