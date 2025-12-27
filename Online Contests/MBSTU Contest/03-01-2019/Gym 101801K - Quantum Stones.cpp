#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
int isprime[1000005], val[1000005];
ll d[10001][101];
vector<pii>adj[10005];
void sieve(){
    for(int i=1; i<=1000000; i++)val[i]=i;
    for(int i=2; i<=1000000; i++){
        if(isprime[i]==0){
            for(int j=i+i; j<=1000000; j+=i){
                isprime[j] = 1;
                val[j] = min(val[j], (j/i)+(i+i));
            }
        }
    }
}
ll Dijkstra(int src, int des,int k){
    if(src==des)return 0;
    for(int i=0; i<=10000; i++){
        for(int j=0; j<=100; j++){
            d[i][j] = 1e18;
        }
    }
    queue<pii>Q;
    Q.push(make_pair(src,k));
    for(int i=0; i<=k; i++) d[src][i] = 0;
    ll ans = 1e18;
    while(!Q.empty()){
        pii cur = Q.front();
        Q.pop();
        int u = cur.first;
        int cnt = cur.second;
        for(int i=0; i<adj[u].size(); i++){
            pii temp = adj[u][i];
            int v = temp.first;
            int w = temp.second;
            if(cnt>0){
                if(d[u][cnt]+w<d[v][cnt]){
                    d[v][cnt] = d[u][cnt]+w;
                    if(v==des)ans = min(ans,d[v][cnt]);
                    Q.push(make_pair(v,cnt));
                }
                if(d[u][cnt]+val[w]<d[v][cnt-1]){
                    d[v][cnt-1] = d[u][cnt]+val[w];
                    if(v==des)ans = min(ans,d[v][cnt-1]);
                    Q.push(make_pair(v,cnt-1));
                }
            }else{
                if(d[u][cnt]+w<d[v][cnt]){
                    d[v][cnt] = d[u][cnt]+w;
                    if(v==des)ans = min(ans,d[v][cnt]);
                    Q.push(make_pair(v,cnt));
                }
            }
        }
    }
    if(ans>=1e18)return -1;
    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();
    int tt; cin>>tt;
    while(tt--){
        int n,m,k; cin>>n>>m>>k;
        for(int i=1; i<=m; i++){
            int u,v,w; cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        int src,des; cin>>src>>des;
        ll ans = Dijkstra(src,des,k);
        cout<<ans<<endl;
        for(int i=1; i<=n; i++)adj[i].clear();
    }
    return 0;
}
