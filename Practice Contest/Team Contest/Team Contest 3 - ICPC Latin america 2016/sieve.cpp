#include<bits/stdc++.h>
using namespace std;
#define MAXN 171420
int cnt[MAXN+5],ans[MAXN+5];
void sieve()
{
    for(int i=2; i<=MAXN; i++)
    {
        if(cnt[i]==0){
            for(int j=i; j<=MAXN; j+=i){
                cnt[j]++;
            }
        }
    }

    int k=0;
    for(int i=1; i<=MAXN; i++){
        if(cnt[i]>=3){
            ans[++k] = i;
        }
    }
}
int main()
{
    sieve();
    int tt; scanf("%d",&tt);

    while(tt--)
    {
        int n; scanf("%d",&n);
        printf("%d\n",ans[n]);
    }

    return 0;
}
