#include<bits/stdc++.h>
using namespace std;
int N,M,L;
bool vis[10005];
int hand[10005];
vector<int>ed[10005];
void RESET()
{
    for(int i=0;i<=N; i++){
        vis[i]=false;
        ed[i].clear();
    }
}
void DFS(int u)
{
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++){
        if(vis[ed[u][i]]==false){
            DFS(ed[u][i]);
        }
    }

    return;
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        RESET();

        scanf("%d%d%d",&N,&M,&L);

        for(int i=0; i<M; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            ed[x].push_back(y);
        }

        for(int i=0; i<L; i++){
            scanf("%d",&hand[i]);
        }

        for(int i=0; i<L; i++){
            if(vis[hand[i]]==false){
                DFS(hand[i]);
            }
        }

        int cnt=0;
        for(int i=1; i<=N; i++){
           if(vis[i]==true){
            cnt++;
           }

        }

        printf("%d\n",cnt);
    }

    return 0;
}
