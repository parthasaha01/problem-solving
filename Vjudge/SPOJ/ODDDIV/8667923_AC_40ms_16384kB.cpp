#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>pr;
bool flag[505];
vector<ll>ans[10005];
void sieve()
{
    pr.push_back(2);
    for(int i=3; i<=320; i+=2){
        if(!flag[i]){
            pr.push_back(i);
            for(int j=i*i; j<=320; j+=2*i){
                flag[j]=true;
            }
        }
    }

}
int NumberOfDivisor(int v)
{
    int cnt=1;
    int sz = pr.size();
    for(int i=0; i<sz && pr[i]*pr[i]<=v; i++)
    {
        int k=0;
        while(v%pr[i]==0)
        {
            v/=pr[i];
            k+=2;
        }
        cnt *= (k+1);
    }

    if(v>1)cnt*=3;
    return cnt;
}
void SolutionSet()
{
    for(ll i=1; i<=100000; i++)
    {
        ll v=(ll)i*i;
        int cnt=NumberOfDivisor(i);
        ans[cnt].push_back(v);
    }
}
int main()
{
    sieve();
    SolutionSet();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll lo,hi; int k;
        scanf("%d%lld%lld",&k,&lo,&hi);
        if(lo>hi)swap(lo,hi);
        int res1 = lower_bound(ans[k].begin(),ans[k].end(),lo) - ans[k].begin();
        int res2 = upper_bound(ans[k].begin(),ans[k].end(),hi) - ans[k].begin();
        int res = res2-res1;
        printf("%d\n",res);
    }

    return 0;
}
