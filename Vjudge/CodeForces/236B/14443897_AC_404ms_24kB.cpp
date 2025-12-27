#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1073741824LL
int vis[105],cnt[105][30];
void sieve()
{
    for(int i=2,x=0; i<=100; i++){
        if(vis[i]==0){
            x++;
            for(int j=i; j<=100; j+=i){
                int v = j;
                while(v%i==0){
                    cnt[j][x]++;
                    v/=i;
                }
                vis[j]=1;
            }
        }
    }
}
int main()
{
    sieve();
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    ll ans = 0;
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            for(int k=1; k<=c; k++){
                ll d = 1;
                for(int x=1; x<=25; x++){
                    d *= (ll)(cnt[i][x]+cnt[j][x]+cnt[k][x]+1);
                    d %= MOD;
                }
                ans += d;
                ans %= MOD;
            }
        }
    }

    printf("%I64d\n",ans);

    return 0;
}
