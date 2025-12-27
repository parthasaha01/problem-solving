#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000005
bool flag[mx+5];
int cnt[mx+5];
void sieve()
{
    flag[0]=flag[1]=true;
    for(ll i=2; i<=1001; i++){
        if(!flag[i]){
            for(ll j=i*i; j<=mx; j+=i){
                flag[j]=true;
            }
        }
    }

    for(int i=1; i<=mx; i++){
        if(!flag[i])
            cnt[i] = cnt[i-1]+1;
        else
            cnt[i] = cnt[i-1];
    }
}
bool check(int a,int b,int k,int v)
{
    for(int i=a; i+v-1<=b; i++)
    {
        int tm = cnt[i+v-1]-cnt[i-1];
        if(tm<k)return false;
    }
    return true;
}
int fun(int a, int b,int k)
{
    int lo=1;
    int hi=b-a+1;
    int ans=-1;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(check(a,b,k,md)){
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
    sieve();

    int a,b,k;

    while(scanf("%d%d%d",&a,&b,&k)==3)
    {
        int ans = fun(a,b,k);
        printf("%d\n",ans);
    }
    return 0;
}
