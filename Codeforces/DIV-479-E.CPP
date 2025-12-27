#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200005

vector<int>ed[mx];
int vis[mx];
int n,m,cnt,flag;
void DFS(int u,int pr)
{
    vis[u]=1;
    int ase = 0;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==pr)continue;
        ase=1;
        if(vis[v]==0){
            DFS(v,u);
        }
        else if(vis[v]==1){
            cnt++;
        }
    }

    if(ase==0){
        flag = 0;
    }
    vis[u]=2;
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }


    int ans=0;
    for(int i=1; i<=n; i++)
    {
        cnt = 0;
        flag = 1;
        if(vis[i]==0){
            DFS(i,i);
            if(cnt==1 && flag==1){
                ans++;
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}
/*
5 5
1 2
1 4
3 2
4 3
3 5
*/
