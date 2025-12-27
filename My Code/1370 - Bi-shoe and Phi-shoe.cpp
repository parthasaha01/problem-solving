#include<bits/stdc++.h>
using namespace std;
#define ll long long
int vis[1000105],a[10005];
vector<int>pr;
void sieve()
{
    pr.push_back(2);
    for(ll i=3; i<=1000100; i+=2)
    {
        if(vis[i]==0)
        {
            pr.push_back(i);
            for(ll j=i*i; j<=1000100; j+=2*i)
            {
                vis[j]=1;
            }
        }
    }
}
int main()
{
    sieve();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }

        ll ans = 0;
        for(int i=1; i<=n; i++)
        {
            int v = a[i];
            if(v==1){
                ans+=2;
                continue;
            }
            int k = lower_bound(pr.begin(),pr.end(),v)-pr.begin();
            if(pr[k]==v)k++;
            ans += pr[k];
            //cout << pr[k] << " ";
        }

        //cout << endl;

        printf("Case %d: %lld Xukha\n",ks,ans);
    }

    return 0;
}
