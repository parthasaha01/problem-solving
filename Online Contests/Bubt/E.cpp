#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll fac[15];
void factorial()
{
    fac[0]=1;
    for(int i=1; i<=10; i++){
        fac[i]=fac[i-1]*i;
    }
}
ll calculate(ll k)
{
    ll cnt=0;
    for(ll x=1; x<=k; x++){
        for(ll y=1; y<=k; y++){
            if(x!=y && x!=1 && y!=2){
                cnt++;
            }
        }
    }
    return cnt;
}
ll bigmod(ll b,ll p)
{
    ll res=1;
    if(p==1){
        return b%mod;
    }

    if(p%2==0){
        res = (bigmod(b,p/2)%mod);
        res = ((res%mod)*(res%mod))%mod;
    }
    else{
        res = ((bigmod(b,p-1)%mod)*(b%mod)%mod);
    }

    return res%mod;
}
int main()
{
    factorial();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll m,k;
        scanf("%lld%lld",&m,&k);

        if(k<2||m==0)
        {
            printf("0\n");
        }
        else
        {
            ll f1=fac[k]/fac[k-2];
            ll f2=calculate(k);
            //cout << f2 << endl;
            ll bgm=1;
            if(m>1){
                bgm=bigmod(f2,m-1);
            }
            ll ans=((f1%mod)*(bgm%mod))%mod;
            printf("%lld\n",ans);
        }
    }

    return 0;
}
