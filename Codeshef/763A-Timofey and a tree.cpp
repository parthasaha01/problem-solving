#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx+5],flag,n1,n2,root;
vector<int>ed[mx+5];
void DFS(int u,int pr)
{
    if(flag==1)return;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;
        if(a[u]!=a[v]){
            flag = 1;
            n1 = u; n2 = v;
            return;
        }
        if(flag==0)
            DFS(v,u);
    }
}
void DFS1(int u,int pr)
{
    if(flag==1)return;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;
        if(a[u]!=a[v] && u!=root){
            flag = 1;
            return;
        }
        if(flag==0)
            DFS1(v,u);
    }
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    DFS(1,0);

    if(flag==0){
        printf("YES\n");
        printf("1\n");
        return 0;
    }

    //cout << n1 << " " << n2 << endl;
    flag = 0;
    root=n1;
    DFS1(n1,0);

    if(flag==0){
        printf("YES\n");
        printf("%d\n",n1);
        return 0;
    }

    flag = 0;
    root = n2;
    DFS1(n2,0);

    if(flag==0){
        printf("YES\n");
        printf("%d\n",n2);
        return 0;
    }

    printf("NO\n");

    return 0;
}
