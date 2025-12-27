#include<bits/stdc++.h>
using namespace std;
#define ll long long
int vis[200];
vector<ll>pr;
ll cnt[100];
void sieve()
{
    pr.push_back(2);

    for(ll i=3; i<=100; i+=2){
        if(vis[i]==0){
            pr.push_back(i);
            for(ll j=i*i; j<=100; j+=2*i){
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
        ll n; scanf("%lld",&n);

        if(n==1){
            printf("1 1\n");
            continue;
        }

        ll sum=1;
        bool flag = true;
        memset(cnt,0,sizeof(cnt));

        for(int i=2; i<=100; i++){
            if(sum*i<=n && sum*i>sum){
                sum *= i;
            }
        }

        ll nn=1;
        n = sum;
        for(int i=0; i<pr.size() && pr[i]*pr[i]<=n; i++)
        {
            if(n%pr[i]==0)
            {
                int cnt = 0;

                while(n%pr[i]==0){
                    cnt++;
                    n /= pr[i];
                }
                nn *= (cnt+1);
            }
        }

        printf("%lld %lld\n",sum,nn);

    }

    return 0;
}
