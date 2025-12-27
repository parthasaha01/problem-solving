#include<bits/stdc++.h>
using namespace std;
//#define ld double
#define ll long long
double fun(ll n,ll r)
{
    ll nr = n-r;
    if(r>nr)swap(r,nr);

    ll tot = (1LL<<n);
    double sum = (double)tot;
    double cur=1.0;
    for(ll i=nr+1; i<=n; i++){
        cur*=(double)i;
    }
    double pp=1.0;
    for(ll i=1; i<=r; i++){
        pp*=(double)i;
    }
    cur = cur/pp;
    double res = cur/sum;
    return res;
}
int main()
{
    int tt; scanf("%d",&tt);
    while(tt--)
    {
        ll n,a,b;
        scanf("%lld %lld %lld",&n,&a,&b);
        double ret1 = fun(n,a);
        double ret2 = fun(n,b);
        double ret = ret1+ret2;
        printf("%.6f\n",ret);
        //cout << ret1 << " " << ret2 << " " << ret << endl;
    }
    return 0;
}
