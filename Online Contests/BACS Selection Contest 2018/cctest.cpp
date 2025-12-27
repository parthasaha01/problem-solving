#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ans[100005];
ll Find(ll x)
{
    if(x==1)return 1LL;
    ll v = 1;
    while(v<=x){
        v=(v<<1LL);
    }
    v >>= 1LL;
    return v;
}
ll solve(ll X, ll L, ll N)
{
    ll cnt = 0;
    if(X>L)cnt+=(X-L);
    if(X%2==0)return cnt;

    ll pp = Find(X);
    //printf("pp=%lld\n",pp);
    ll cur = pp+(X/2LL);
    //if(cur>N)return cnt;
    ll vv = pp;
    while(cur<=N)
    {
        if(cur>=L)cnt++;
        //printf("cnt=%lld vv=%lld cur=%lld\n",cnt,vv,cur);
        cur += vv;
        vv=(vv<<1LL);
    }

    return cnt;
}
int Fun(int n)
{
    int bit=0;
    while(n!=0) {
        bit++;
        n >>= 1;
    }
    return bit;
}
int solvexx(int n)
{
    int msb = Fun(n);
    int vv = (1<<(msb-1));
    int ans = (n^vv);
    ans <<= 1;
    ans |= 1;
    return ans;
}
int go(int x,int l,int n)
{
    int cnt = 0;
    if(x>l)cnt+=x-l;
    int tot = n-l+1;
    for(int i=l; i<=n; i++){
        if(ans[i]==x)cnt++;
    }
    return cnt;
}
int main()
{
    for(int i=1; i<=100002; i++){
        ans[i] = solvexx(i);
    }

    ll tt; scanf("%lld",&tt);

    for(ll ks=1; ks<=tt; ks++)
    {
        //ll X,L,N; scanf("%lld%lld%lld",&X,&L,&N);

        for(int k=1; k<=100; k++){
            for(int i=1; i<=k; i++){
                for(int j=1; j<=k; j++){
                    ll X=i, L=j, N=k;
                    ll cnt = solve(X,L,N);
                    ll ccc = go(X,L,N);
                    if(cnt!=ccc){
                        printf("%d %d %d\n",i,j,k);
                    }
                }
            }
        }

//        ll tot = N-L+1;
//        ll gcd = __gcd(cnt,tot);
//        ll lob = cnt/gcd;
//        ll hor = tot/gcd;
//        printf("Case %lld: %lld/%lld\n",ks,lob,hor);
    }
    return 0;
}

