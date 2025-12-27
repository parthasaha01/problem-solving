gin#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,middle;
ll k,a[21][21],ans=0;
unordered_map<ll,ll>mp[21][21];
void dfs1(int r,int c,ll v)
{
    if(r>n||c>m)return;

    if(r+c==middle){
        mp[r][c][v^a[r][c]]++;
        return;
    }

    dfs1(r+1,c,v^a[r][c]);
    dfs1(r,c+1,v^a[r][c]);
}
void dfs2(int r,int c,ll v)
{
    if(r<0||c<0)return;

    if(r+c==middle){
        ans += mp[r][c][v^k];
        return;
    }

    dfs2(r-1,c,v^a[r][c]);
    dfs2(r,c-1,v^a[r][c]);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }

    middle = ((n-1+m-1)/2)+2;

    dfs1(1,1,0LL);
    dfs2(n,m,0LL);

    cout<<ans<<endl;

    return 0;
}
