#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
double cost[50][50];
int main()
{
    int n,ks=0;
    while(scanf("%d",&n) && n)
    {
        mp.clear();

        for(int i=1;i<=n; i++)
        {
            string u; cin>>u;
            mp[u]=i;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j)cost[i][j]=1.0;
                else cost[i][j]=0.0;
            }
        }

        int m; scanf("%d",&m);

        for(int i=1; i<=m; i++)
        {
            string u,v; double x;
            cin >> u >> x >> v;
            cost[mp[u]][mp[v]]=x;
        }


        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    cost[i][j] = max(cost[i][j],cost[i][k]*cost[k][j]);
                }
            }
        }

        bool flag = false;
        for(int i=1;i<=n; i++)
        {
            if(cost[i][i]>1.0){
                flag = true;
                break;
            }
        }

        if(flag)printf("Case %d: Yes\n",++ks);
        else printf("Case %d: No\n",++ks);
    }
    return 0;
}
