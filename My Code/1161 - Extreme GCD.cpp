#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10005],d[10005],mob[10005],vis[10005],c[10005][5];
int main()
{
    for(int i=1; i<=10000; i++)mob[i]=1;
    for(ll i=2; i<=10000; i++){
        if(vis[i]==0){
            mob[i]=-1;
            for(ll j=i+i; j<=10000; j+=i){
                if(j%(i*i)==0)mob[j]=0;
                mob[j] *= (-1);
                vis[j]=1;
            }
        }
    }
    c[0][4]=c[1][4]=c[2][4]=c[3][4]=0;
    for(ll i=4; i<=10000; i++){
        ll v = (i*(i-1)*(i-2)*(i-3))/ (1*2*3*4);
        c[i][4]=v;
    }

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++)scanf("%lld",&a[i]);

        memset(d,0,sizeof(d));

        for(int i=1; i<=n; i++){
            int v = a[i];
            for(int j=1; j*j<=v; j++){
                if(v%j==0){
                    d[j]++;
                    if(j!=(v/j))d[v/j]++;
                }
            }
        }

        ll ans = c[n][4];

        for(int i=2; i<=10000; i++){
            ans += (mob[i]*c[d[i]][4]);
        }

        printf("Case %d: %lld\n",ks,ans);
    }
    return 0;
}
