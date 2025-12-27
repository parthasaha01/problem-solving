#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,deg[mx+5];
vector<int>ed[mx+5];
vector<int>ans;
void DFS(int u,int pr)
{
    int f = 1;
    //cout << ed[u].size() << " " << u << " " << pr << endl;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;
        f = 0;
        DFS(v,u);
    }

    if(f)ans.push_back(u);
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<n; i++){
        int u, v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int f = 0,flag=0;
    for(int i=1; i<=n; i++){
        if(deg[i]>2){
            if(f==1){
                flag = 1;
                break;
            }
            else{
                f++;
            }
        }
    }

    if(flag){
        printf("No\n");
        return 0;
    }

    int root = 1,maxx=0;
    for(int i=1; i<=n; i++){
        if(deg[i]>maxx){
            root = i;
            maxx = deg[i];
        }
    }

    DFS(root,0);

    int cnt = ans.size();
    printf("Yes\n");
    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++){
        printf("%d %d\n",root,ans[i]);
    }

    return 0;
}
