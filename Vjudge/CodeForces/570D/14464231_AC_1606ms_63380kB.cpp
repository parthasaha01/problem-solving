#include<bits/stdc++.h>
using namespace std;
#define mx 500001
int n,q,cnt,dis[mx],fin[mx],depth[mx];
bool frq[26];
//int height[mx];
string s;
vector<int>ed[mx];
vector<int>level[mx];
vector<int>cum[mx];
void dfs(int u,int p)
{
    dis[u] = ++cnt;
    depth[u]= depth[p]+1;
    //height[u] = depth[u];
    level[depth[u]].push_back(u);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==p)continue;
        dfs(v,u);
        //height[u] = max(height[u],height[v]);
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
            int u = level[x][i];
            if(i>0){
                cum[x][i]=cum[x][i-1];
            }
            else{
                cum[x][i]=0;
            }
            int c = s[u-1]-'a';
            cum[x][i] = (cum[x][i]^(1<<c));
        }
    }

//    for(int x=1; level[x].size()>0; x++)
//    {
//        int sz = level[x].size();
//        printf("level=%d size=%d:\n",x,sz);
//        for(int i=0; i<level[x].size(); i++){
//            printf("pos=%d:\n",i);
//            for(int c=0; c<26; c++){
//                if(cum[x][c][i]>0)printf("c=%d cnt=%d\n",c,cum[x][c][i]);
//            }
//            printf("\n");
//        }
//        printf("----------\n");
//    }
}
int Lower_Bound(int v,int h)
{
    int lo = 0;
    int hi = level[h].size()-1;
    int l=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int u = level[h][md];
        if(dis[u]>=dis[v]&&fin[u]<=fin[v]){
            l = md;
            hi = md-1;
        }
        else if(dis[u]>fin[v]){
            hi = md-1;
        }
        else{
            lo = md+1;
        }
    }
    return l;
}
int Upper_Bound(int v,int h)
{
    int lo = 0;
    int hi = level[h].size()-1;
    int r=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int u = level[h][md];
        if(dis[u]>=dis[v]&&fin[u]<=fin[v]){
            r = md;
            lo = md+1;
        }
        else if(dis[u]>fin[v]){
            hi = md-1;
        }
        else{
            lo = md+1;
        }
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

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

//        if(h>height[v]){
//            cout << "Yes" << endl;
//            continue;
//        }
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

        //memset(frq,false,sizeof(frq));
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
