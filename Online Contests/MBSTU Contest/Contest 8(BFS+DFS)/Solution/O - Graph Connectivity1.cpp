#include<bits/stdc++.h>
using namespace std;
bool vis[30],color[30];
vector<int>ed[30];
void RESET()
{
    for(int i=0; i<30; i++){
        vis[i]=false;
        ed[i].clear();
    }
}
void dfs(int u)
{
    vis[u]=true;
    for(int i=0; i<ed[u].size(); i++){
        if(vis[ed[u][i]]==false){
            dfs(ed[u][i]);
        }
    }

}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        RESET();

        string sn;
        cin >> sn;
        int n=sn[0]-64;

        while(1)
        {
            string ss;
            cin >> ss;
            if(ss[0])
                break;

            //cout << ss<<endl;

            int u=ss[0]-64;
            int v=ss[1]-64;

            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        //cout << "partha" << endl;
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==false ){
               dfs(i);
               ++cnt;
            }
        }

        printf("%d\n",cnt);
        if(t!=0)
            printf("\n");

    }

    return 0;
}
