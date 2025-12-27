#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int a[mx],tree[4*mx],n;
ll lft[mx],rgt[mx];
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd] = a[b];
        return;
    }

    int lf = 2*nd; int rg = 2*nd+1; int md = (b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);

    tree[nd] = max(tree[lf],tree[rg]);
}
int query(int nd,int b,int e,int x,int y)
{
    if(b==x &&e==y){
        return tree[nd];
    }

    int lf = 2*nd; int rg = 2*nd+1; int md = (b+e)/2;

    if(y<=md){
        return query(lf,b,md,x,y);
    }
    else if(x>md){
        return query(rg,md+1,e,x,y);
    }
    else{
        int p1 = query(lf,b,md,x,md);
        int p2 = query(rg,md+1,e,md+1,y);
        return max(p1,p2);
    }
}
int solveleft(int l,int r,int v)
{
    int lo=l, hi=r;
    int ans=0;
    while(lo<=hi)
    {
        int md=(lo+hi)/2;
        int x = query(1,1,n,md,r);
        if(x>v){
            ans = md;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }

    return ans;
}
int solveright(int l,int r,int v)
{
    int lo=l, hi=r;
    int ans=0;
    while(lo<=hi)
    {
        int md=(lo+hi)/2;
        int x = query(1,1,n,l,md);
        if(x>v){
            ans = md;
            hi = md-1;
        }
        else{
            lo = md+1;
        }
    }

    return ans;
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    //memset(tree,0,sizeof(tree));
    init(1,1,n);

    int maxx = 0;
    for(int i=1; i<=n; i++)
    {
        if(i==1){
            maxx = max(maxx,a[i]);
            lft[i] = 0;
            continue;
        }
        if(a[i]>=maxx){
            maxx = max(maxx,a[i]);
            lft[i] = 0;
            continue;
        }

        int v = solveleft(1,i-1,a[i]);
        //printf("i=%d v=%d\n",i,v);
        lft[i] = v;

        maxx = max(maxx,a[i]);
    }

//    for(int i=1; i<=n; i++){
//        printf("%lld ",lft[i]);
//    }
//    printf("\n");

    maxx = 0;
    for(int i=n; i>=1; i--)
    {
        if(i==n){
            maxx = max(maxx,a[i]);
            rgt[i] = 0;
            continue;
        }
        if(a[i]>=maxx){
            maxx = max(maxx,a[i]);
            rgt[i] = 0;
            continue;
        }

        int v = solveright(i+1,n,a[i]);
        rgt[i] = v;
        maxx = max(maxx,a[i]);
    }
    ll ret = -100000000000000000LL;
    for(int i=1; i<=n; i++)
    {
        ll v = lft[i]*rgt[i];
        if(v>ret){
            ret = v;
        }
    }

    printf("%lld\n",ret);

    return 0;
}
