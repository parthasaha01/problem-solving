#include<bits/stdc++.h>
using namespace std;
int a[300005],par[300005],vis[300005],dp[300005][27];
vector<int>ed[300005];
//pair<int,int>pi;
map< pair<int,int> , int>mp;
int flag;
int ans;
void DFS(int u)
{
    //cout << "u=" << u << endl;
    //getchar();
    if(flag==1)return;
    vis[u]=1;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(flag==1)return;
        if(vis[v]==1){
            //cout << "u="  << u << " v=" << v << endl;
            flag=1;
            return;
        }

        if(vis[v]==0)DFS(v);
        for(int j=0; j<26; j++)
        {
            dp[u][j] = max(dp[u][j],dp[v][j]);
        }

    }
    vis[u]=2;
    dp[u][a[u]]++;
}
int main()
{
    int n,m; scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    for(int i=1; i<=n; i++)
    {
        a[i] = s[i-1]-'a';
        par[i] = i;
        vis[i]=0;
    }

    flag = 0;

    for(int i=1; i<=m; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        pair<int,int> pi = make_pair(u,v);
        if(mp[pi]==0){
            //cout << "u="  << u << " v=" << v << endl;
            ed[u].push_back(v);
        }
        mp[pi]=1;
        par[v]=u;
        //if(u==v)flag=1;
    }

    if(flag==1){
       // cout << "partha1" << endl;
        printf("-1\n");
        return 0;
    }


    flag = 0;
    int ase=1;

    vector<int>uu;
    for(int i=0; i<26; i++)uu.push_back(0);

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            ase=0;
            DFS(i);
        }
    }

    if(ase==1){
        //cout << "partha2" << endl;

        printf("-1\n");
        return 0;
    }

    if(flag==1){
        //cout << "partha3" << endl;

        printf("-1\n");
        return 0;
    }

    //cout << "partha4" << endl;
    ans = 0;

    for(int u=1; u<=n; u++)
    {
        for(int i=0; i<26; i++){
            ans = max(ans,dp[u][i]);
        }
    }

    printf("%d\n",ans);

    return 0;

}
