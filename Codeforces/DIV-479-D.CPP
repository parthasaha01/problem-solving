#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>mp;
map<ll,ll>sp;
vector<ll>ed[105],res;
int vis[105],fr[105],dd[105];
ll a[105],b[105];
int n,k,N,cnt;
void DFS(int u)
{
    //vis[u] = 1;
    cnt++;
    dd[u]--;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(dd[v]>0){
            DFS(v);
        }
    }
}
void fun(int u)
{
    //vis[u] = 1;
    cnt++;
    dd[u]--;
    res.push_back(u);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(dd[v]>0){
            fun(v);
        }
    }
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%I64d",&a[i]);
        b[i] = a[i];
    }

    sort(b+1,b+n+1);

    k = 0;
    memset(fr,0,sizeof(fr));
    for(int i=1; i<=n; i++){

        if(mp.find(b[i])==mp.end()){
            mp[b[i]] = ++k;
            sp[k] = b[i];
        }

        fr[mp[b[i]]]++;
    }

    N = k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i]%3==0){
                if(mp.find(a[i]/3)!=mp.end()){
                    ll u = mp[a[i]];
                    ll v = mp[a[i]/3];
                    ed[u].push_back(v);
                }
            }
            //if(a[i]%3==0){
            if(mp.find(a[i]*2)!=mp.end()){
                ll u = mp[a[i]];
                ll v = mp[a[i]*2];
                ed[u].push_back(v);
            }
            //}
        }
    }

    int ans=1;
    for(int i=1; i<=N; i++)
    {
        for(int i=1; i<=N; i++)dd[i]=fr[i];

        cnt = 0;
        DFS(i);

        if(cnt==n){
            ans = i;
            break;
        }
    }

    for(int i=1; i<=N; i++)dd[i]=fr[i];
    fun(ans);

    for(int i=0; i<n; i++){
        if(i==n-1){
            printf("%I64d\n",sp[res[i]]);
        }
        else{
            printf("%I64d ",sp[res[i]]);
        }
    }

    return 0;
}
