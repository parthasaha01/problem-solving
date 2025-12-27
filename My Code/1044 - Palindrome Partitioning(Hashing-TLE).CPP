#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 101949101;
const ll BASE = 1000117;
string s;
int n,dp[1005];
ll fr[1005],rv[1005],power[1005],ispalindrome[1005][1005];
ll BIGMOD(ll b,ll p)
{
    ll ans = 1%MOD, k = b%MOD;
    while(p){
        if(p&1LL){
            ans *= k; ans %= MOD;
        }
        k*=k; k%=MOD;
        p = p>>1LL;
    }
    return ans;
}
ll MODINVERSE(ll b)
{
    return BIGMOD(b,MOD-2);
}
void palindrome()
{
    for(int i=0,j=0; i<n; i++,j++){
        if(i==0) fr[i] = s[i]*power[j];
        else fr[i] = fr[i-1]+(s[i]*power[j]);
        fr[i] %= MOD;
    }

    for(int i=n-1,j=0; i>=0; i--,j++)
    {
        if(i==n-1)rv[i] = s[i]*power[j];
        else rv[i] = rv[i+1] + (s[i]*power[j]);
        rv[i] %= MOD;
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i==j){
                ispalindrome[i][j] = 1;
                continue;
            }

            ll x,y;

            if(i==0) x = fr[j];
            else{
                x = fr[j]-fr[i-1];
                if(x<0) x = (x+MOD)%MOD;
                x *= MODINVERSE(power[i]);
                x %= MOD;
            }


            if(j==n-1) y = rv[i];
            else{
                y = rv[i] - rv[j+1];
                if(y<0) y = (y+MOD)%MOD;
                y *= MODINVERSE(power[n-j-1]);
                y %= MOD;
            }

            if(x==y)ispalindrome[i][j] = 1;
            else ispalindrome[i][j] = 0;
        }
    }

//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            printf("%d %d -> %d\n",i,j,ispalindrome[i][j]);
//        }
//        printf("\n");
//    }
}
int fun(int i)
{
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];

    int ret = 1000000;
    for(int j=i; j<n; j++){
        if(ispalindrome[i][j]==1){
            ret = min(ret,1+fun(j+1));
        }
    }
    return dp[i] = ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    power[0]=1;
    for(ll i=1; i<=1003; i++){
        power[i]=(power[i-1]*BASE)%MOD;
    }

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cin>>s;
        n = s.size();

        palindrome();

        memset(dp,-1,sizeof(dp));
        int ans = fun(0);
        cout<<"Case "<<ks<<": "<<ans<<endl;
    }
    return 0;
}
