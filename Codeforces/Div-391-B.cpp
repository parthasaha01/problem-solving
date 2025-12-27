#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int ar[mx+5],a[mx+5],cnt[mx+5];
vector<int>pr;
void sieve()
{
    pr.push_back(2);

    for(ll i=3; i<=mx; i+=2){
        if(ar[i]==0){
            pr.push_back(i);
            for(ll j=i*i; j<=mx; j+=2*i){
                ar[j] = 1;
            }
        }
    }
}
int main()
{
    sieve();

    for(int i=100; i<200; i++){
        printf("%d\n",pr[i]);
    }

    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }
        memset(cnt,0,sizeof(cnt));

        for(int i=1; i<=n; i++)
        {
            int x = a[i];

            for(int j=0; j<pr.size() && pr[j]*pr[j]<=x; j++)
            {
                if(x%pr[j]==0)
                {
                    while(x%pr[j]==0)
                    {
                        x/=pr[j];
                    }
                    cnt[pr[j]]++;
                }
            }

            if(x>1){
                cnt[x]++;
            }
        }
        int ans = 1;
        for(int i=0; i<pr.size(); i++){
            ans = max(ans,cnt[pr[i]]);
        }

        printf("%d\n",ans);
    }

    return 0;
}
