#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
vector<int>adj[mx];
int n,flag=1,height[mx];
ll s[mx],a[mx];
void dfs(int u,int p,int h){
    height[u] = h;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p)continue;
        dfs(v,u,h+1);
    }
}
void dfs1(int u,int p,ll val){
    if(height[u]%2==1){
        if(s[u]<val){
            flag = 0;
        }
    }

    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p)continue;
        if(height[u]%2==1)dfs1(v,u,s[u]);
        else dfs1(v,u,val);
    }
}
void dfs2(int u,int p,ll val){
    if(height[u]%2==0){
        if(s[u]!=-1){
            flag = 0;
        }
        a[u] = 0;
    }else{
        if(s[u]==-1){
            flag = 0;
        }
        if(s[u]<val){
            flag = 0;
            a[u] = 0;
        }else{
            a[u] = s[u]-val;
        }
    }

    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p)continue;
        dfs2(v,u,val+a[u]);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=2; i<=n; i++){
        int p; cin>>p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    for(int i=1; i<=n; i++){
        cin>>s[i];
    }

    dfs(1,0,1);
    flag = 1;
    dfs1(1,0,0);
    dfs2(1,0,0);

    if(flag==0){
        cout<<-1<<endl;
    }else{
        ll ans = 0;
        for(int i=1; i<=n; i++) ans+=a[i];
        cout<<ans<<endl;
    }
    return 0;
}
