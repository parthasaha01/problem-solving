#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a,b;
struct dt{
    ll h,d,i;
    //ll u[22];
}st[200005];
bool cmp(dt a, dt b){
    return a.u[k] > b.u[k];
}
int main()
{
    scanf("%lld",n);
    scanf("%lld",&a,&b);
    k = min(a,b);
    ll maxx = -100000000000000000;
    ll id=0;
    for(int i=1; i<=n; i++){
        ll h,d; scanf("%lld %lld",&h,&d);
        st[i].h = h;
        st[i].d = d;
        st[i].i = i;
        ll vv = ((1LL<<k)*h)-d;
        if(vv>maxx){
            maxx =
        }
        //st[i].u[k] = ((1LL<<k)*h)-d;
    }

    if(b==0){
        ll ret = 0;
        for(int i=1; i<=n; i++){
            ret += st[i].d;
        }
        printf("%lld\n",ret);
        return 0;
    }

    sort(st+1,st+n+1,cmp);

    ll ret = 0;
    for(int )
}
