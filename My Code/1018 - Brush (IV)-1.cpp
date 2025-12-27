#include<bits/stdc++.h>
using namespace std;
struct Point{ int x,y;};
Point P[17];
int n,ks,vis[(1<<17)],m;
int dp[(1<<17)];
vector<int>v,s;
bool cmp(Point a,Point b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
bool colinear(Point a,Point b,Point c){
    if((b.y-a.y)*(c.x-b.x)==(c.y-b.y)*(b.x-a.x))return true;
    return false;
}
int fun(int mask)
{
    if(mask==(1<<n)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ret = 100000;
    for(int i=0; i<v.size(); i++){
        if((mask|v[i])!=mask)ret = min(ret,1+fun(mask|v[i]));
    }
    return dp[mask] = ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d %d",&P[i].x, &P[i].y);
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

//        if(m>110){
//            printf("Case %d: %d\n",ks,5);
//            continue;
//        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(0);
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
/*



4
-3 3
-4 -7
5 0
-3 -8

*/
