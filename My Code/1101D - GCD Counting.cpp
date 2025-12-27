#include<bits/stdc++.h>
using namespace std;
int n, a[200005], dp[200005][25], isprime[200005], par[200005];
vector<int>adj[200005];
vector<int>prime[200005];
void sieve(){
    for(int i=1; i<=200000; i++)isprime[i]=1;
    for(int i=2; i<=200000; i++){
        if(isprime[i]){
            prime[i].push_back(i);
            for(int j=i+i; j<=200000; j+=i){
                prime[j].push_back(i);
                isprime[j] = 0;
            }
        }
    }
}
void dfs(int u,int p){
    par[u] = p;
    for(int i=0; i<prime[a[u]].size(); i++) dp[u][i]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p)continue;
        dfs(v,u);
    }
    for(int i=0; i<prime[a[u]].size(); i++){
        int pr = prime[a[u]][i];
        for(int j=0; j<adj[u].size(); j++){
            int v = adj[u][j];
            if(v==p)continue;
            for(int k=0; k<prime[a[v]].size(); k++){
                int qr = prime[a[v]][k];
                if(pr==qr){
                    dp[u][i] = max(dp[u][i],1+dp[v][k]);
                    break;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<n; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp,0,sizeof(dp));
    dfs(1,0);

//    for(int i=1; i<=n; i++){
//        cout<<i<<":"<<endl;
//        for(int j=0; j<prime[a[i]].size(); j++){
//            int pr = prime[a[i]][j];
//            cout<<pr<<" "<<dp[i][j]<<endl;
//        }
//        cout<<endl;
//    }
//    int q; cin>>q;

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<prime[a[i]].size(); j++){
            ans = max(ans,dp[i][j]);
        }
    }

    for(int u=1; u<=n; u++){
        for(int k=0; k<prime[a[u]].size(); k++){
            int pr = prime[a[u]][k];
            vector<int>vv;
            for(int i=0; i<adj[u].size(); i++){
                int v = adj[u][i];
                if(v==par[u]) continue;
                for(int j=0; j<prime[a[v]].size(); j++){
                    int qr = prime[a[v]][j];
                    if(pr==qr)vv.push_back(dp[v][j]);
                }
            }
            sort(vv.begin(), vv.end());
            reverse(vv.begin(), vv.end());
            int temp = 0;
            int aa=0,bb=0;
            if(vv.size()>0)aa=vv[0];
            if(vv.size()>1) bb = vv[1];
            temp =aa+bb+1;
            ans = max(ans,temp);
        }
    }

    cout<<ans<<endl;

    return 0;
}
