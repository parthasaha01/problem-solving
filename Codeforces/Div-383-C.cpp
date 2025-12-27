#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
int cost[105], a[105];
bool vis[105];
int lcm(int a, int b)
{
    return a*(b/__gcd(a,b));
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        bool flag = true;

        for(int i=1; i<=n; i++){
            memset(vis,false,sizeof(vis));
            int u = i;
            int v = a[i];
            if(u==v){
                cost[u] = 1;
                continue;
            }
            vis[u] = true;
            int cnt = 1;
            while(vis[v]==false)
            {
                vis[v] = true;
                v = a[v];
                cnt++;
            }

            if(u!=v){
                flag = false;
                break;
            }
            else{
                if(cnt%2==1) cost[u] = cnt;
                else cost[u] = cnt/2;
            }
        }

        if(flag==false) printf("-1\n");
        else{
            int ans = cost[1];

            for(int i=2; i<=n; i++){
                ans = lcm(ans,cost[i]);
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}

