#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int a[205],v[205];
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,k;
        scanf("%d%d",&n,&k);

        for(int i=1; i<=n; i++)v[i]=100000000;
        for(int i=1; i<=k; i++){
            scanf("%d",&a[i]);
        }

        sort(a+1,a+k+1);

        for(int i=1; i<=k; i++)
        {
            int cnt=1;
            int x = a[i];
            v[x]=min(v[x],1);

            for(int j=x-1; j>=1; j--){
                cnt++;
                v[j] = min(v[j],cnt);
            }
            cnt = 1;
            for(int j=x+1; j<=n; j++){
                cnt++;
                v[j] = min(v[j],cnt);
            }
        }

        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            ans = max(ans,v[i]);
        }

        printf("%d\n",ans);

    }

    return 0;
}
