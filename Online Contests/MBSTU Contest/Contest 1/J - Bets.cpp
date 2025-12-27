#include<bits/stdc++.h>
using namespace std;
struct type
{
    int idx;
    int t;
} sec[105];
struct data
{
    int l,r,t,c;
} par[105];
bool vis[105];
int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        memset(vis,false,sizeof(vis));

        for(int i=1; i<=m; i++)
        {
            cin >> par[i].l >> par[i].r >> par[i].t >> par[i].c;
        }

        for(int i=1; i<=m; i++)
        {
            int b=par[i].l;
            int e=par[i].r;
            for(int k=b; k<=e; k++)
            {
                if(vis[k]==true)
                {
                    if(par[i].t<sec[k].t)
                    {
                        sec[k].idx=i;
                        sec[k].t = par[i].t;
                    }
                }
                else
                {
                    sec[k].idx=i;
                    sec[k].t = par[i].t;
                }

                vis[k]=true;
            }
        }
        int profit=0;
        for(int i=1; i<=n; i++){
            if(vis[i]==true)
            {
                profit += par[sec[i].idx].c;
            }
        }
        cout << profit << endl;
    }

    return 0;
}
