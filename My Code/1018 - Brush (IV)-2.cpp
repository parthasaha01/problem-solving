#include<bits/stdc++.h>
using namespace std;
struct Point{ int x,y;};
Point P[16];
int n,ks,vis[(1<<16)],m;
int dp[120][(1<<16)];
vector<int>v,s;
bool cmp(Point a,Point b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
bool colinear(Point a,Point b,Point c)
{
    if((b.y-a.y)*(c.x-b.x)==(c.y-b.y)*(b.x-a.x))return true;
    return false;
}
int fun(int pos,int mask)
{
    if(mask==(1<<n)-1)return 0;
    if(pos==m)return 100000;
    if(dp[pos][mask]==ks)return dp[pos][mask];
    int ret = 100000;
    if((mask|v[pos])!=mask)ret = min(ret,1+fun(pos+1,mask|v[pos]));
    ret = min(ret,fun(pos+1,mask));
    return dp[pos][mask] = ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>P[i].x>>P[i].y;
        }

        sort(P,P+n,cmp);

        v.clear();
        memset(vis,0,sizeof(vis));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)continue;
                s.clear();
                s.push_back(i);
                s.push_back(j);
                for(int k=0; k<n; k++){
                    if(i==k||j==k)continue;
                    bool f = colinear(P[i],P[j],P[k]);
                    if(f)s.push_back(k);
                }
                int mask = 0;
                for(int z=0; z<s.size(); z++){
                    mask |= (1<<s[z]);
                }

//                for(int z=0; z<s.size(); z++){
//                    printf("%d ",s[z]);
//                }
//                printf("   -- %d vis=%d\n",mask,vis[mask]);

                if(vis[mask]==0){
                    vis[mask]=1;
                    v.push_back(mask);
                }
            }
        }

        m = v.size();
//        cout << "sz=" << sz << endl;
//        for(int i=0; i<sz; i++){
//            cout << v[i] << " ";
//        }
        cout << endl;
        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0);
        cout<<"Case "<<ks<<": "<<ans<<endl;
    }
}

