#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long
int pr[mx+5],par[mx+5];
set<int>factor,ar,prime;
bool vis[mx+5];
void sieve()
{
    for(int i=1; i<=mx; i+=2) pr[i] = i;
    for(int i=2; i<=mx; i+=2) pr[i] = 2;

    for(ll i=3; i<=mx; i+=2){
        if(pr[i]==i){
            for(ll j=i*i; j<=mx; j+=2*i){
                pr[j] = i;
            }
        }
    }
}
int Find(int x)
{
    if(par[x]==x) return x;
    return par[x] = Find(par[x]);
}
void Union(int a, int b)
{
    par[Find(b)] = Find(a);
}
int main()
{
    sieve();

    int t; scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        int n; scanf("%d",&n);
        ar.clear();
        int ans = 0;

        for(int i=1; i<=n; i++){
            int x; scanf("%d",&x);
            if(x==1) ans++;
            else ar.insert(x);
        }
        int cnt=0;
        for(int i=2; i<=mx; i++)
            if(pr[i]==i)par[i] = i;

        prime.clear();
        set<int>::iterator it,it1,it2;

        for(it=ar.begin(); it != ar.end(); it++){
            int x = *it;
            factor.clear();
            while(x!=1){
                factor.insert(pr[x]);
                x /= pr[x];
            }
            int a,b;
            a = *factor.begin();

            for(it1=factor.begin(); it1!=factor.end(); it1++){
                prime.insert(*it1);
                b = *it1;
                Union(a,b);
            }
        }

        for(it2=prime.begin(); it2!=prime.end(); it2++){
            int x = *it2;
            if(par[x]==x) ans++;
        }

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}

