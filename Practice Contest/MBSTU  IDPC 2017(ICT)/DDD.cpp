#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1005],b[1005],c[1005];
map<ll,int>mp;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll sa,sb,sc,ss;
        scanf("%lld%lld%lld%lld",&sa,&sb,&sc,&ss);

        for(int i=1; i<=sa; i++)scanf("%lld",&a[i]);
        for(int i=1; i<=sb; i++)scanf("%lld",&b[i]);
        for(int i=1; i<=sc; i++)scanf("%lld",&c[i]);

        if(sa==0 || sb==0 || sc==0){
            printf("Case %d: NO\n",ks);
            continue;
        }

        mp.clear();
        for(int i=1; i<=sc; i++)mp[c[i]]=1;

        bool flag = false;

        for(int i=1; i<=sa; i++){
            for(int j=1; j<=sb; j++){
                ll v = ss-a[i]-b[j];
                if(mp[v]==1){ flag=true; break; }
            }
            if(flag)break;
        }

        if(flag)printf("Case %d: YES\n",ks);
        else printf("Case %d: NO\n",ks);
    }
    return 0;
}

