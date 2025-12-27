#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dt{
    ll v,ys,ns;
}st[200005];
ll a[200005],xx,yy;
bool cmp1(dt p,dt q)
{
    return p.ys<q.ys;
}
bool cmp2(dt p,dt q)
{
    return p.ns<q.ns;
}
void fun(ll n,int id)
{
    st[id].v = n;
    ll sq = sqrt(n);

    if(sq*sq==n){
        st[id].ys = 0;
        if(n==0)st[id].ns = 2;
        else st[id].ns = 1;
        xx++;
    }
    else{
        st[id].ns = 0;
        ll x = sq*sq;
        ll y = (sq+1)*(sq+1);
        ll d = min(n-x,y-n);
        st[id].ys = d;
        yy++;
    }
}
int main()
{
    ll n; scanf("%I64d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        fun(a[i],i);
    }

    if(xx==yy){
        printf("0\n");
        return 0;
    }

    if(xx<yy){
        sort(st+1,st+n+1,cmp1);
        ll ans = 0;
        ll k = (n/2)-xx;
        for(int i=1; i<=n && k>0; i++)
        {
            if(st[i].ys>0){
                ans += st[i].ys;
                k--;
            }
        }
        printf("%I64d\n",ans);
    }
    else{
        sort(st+1,st+n+1,cmp2);
        ll ans = 0;
        ll k = (n/2)-yy;
        for(int i=1; i<=n && k>0; i++)
        {
            if(st[i].ns>0){
                ans += st[i].ns;
                k--;
            }
        }
        printf("%I64d\n",ans);
    }

    return 0;
}
