#include<bits/stdc++.h>
using namespace std;
#define mx 500001
int n,q,cnt,dis[mx],fin[mx],depth[mx];
vector<int>ed[mx],level[mx],cum[mx];
string s;

void dfs(int u,int p)
{
    dis[u] = ++cnt;
    depth[u]= depth[p]+1;
    level[depth[u]].push_back(u);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==p)continue;
        dfs(v,u);
    }
    fin[u]=++cnt;
}
void preprocess()
{
    for(int x=1; level[x].size()>0; x++)
    {
        int sz = level[x].size();
        cum[x].resize(sz);

        for(int i=0; i<level[x].size(); i++)
        {
            if(i>0) cum[x][i]=cum[x][i-1];
            else cum[x][i]=0;

            int u = level[x][i];
            int c = s[u-1]-'a';
            cum[x][i] = (cum[x][i]^(1<<c));
        }
    }
}
int Lower_Bound(int v,int h)
{
    int l=0, lo=0, hi=level[h].size()-1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int u = level[h][md];
        if(dis[u]>=dis[v]&&fin[u]<=fin[v]){
            l = md; hi = md-1;
        }
        else if(dis[u]>fin[v]) hi = md-1;
        else lo = md+1;
    }
    return l;
}
int Upper_Bound(int v,int h)
{
    int r=0, lo=0, hi=level[h].size()-1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int u = level[h][md];
        if(dis[u]>=dis[v]&&fin[u]<=fin[v]){
            r = md; lo = md+1;
        }
        else if(dis[u]>fin[v]) hi = md-1;
        else lo = md+1;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for(int i=2; i<=n; i++){
        int p; cin>>p;
        ed[i].push_back(p);
        ed[p].push_back(i);
    }

    cin>>s;

    dfs(1,0);
    preprocess();

    while(q--)
    {
        int v,h; cin>>v>>h;
        if(h<=depth[v]){
            cout << "Yes" << endl;
            continue;
        }

        int l = Lower_Bound(v,h);
        int r = Upper_Bound(v,h);

        if(l==r){
            cout << "Yes" << endl;
            continue;
        }

        int bit = cum[h][r];
        if(l>0) bit ^= cum[h][l-1];


        int k=__builtin_popcount(bit);
        int sz = r-l+1;
        if(sz%2==0){
            if(k==0)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            if(k==1)cout << "Yes" << endl;
            else cout << "No" << endl;;
        }
    }
    return 0;
}
