#include<bits/stdc++.h>
using namespace std;
int n,m,dp[1005][1005];
bool vv[1005][1005];
vector<int>ww[1005];
bool valid(int x,int y)
{
    if(x>n || y>m || vv[x][y]==false)return false;
    return true;
}
int fun(int x,int y)
{
    if(x==n&&y==m)return 1;

    if(dp[x][y]!=-1)return dp[x][y];

    int ret=0;
    if(valid(x+1,y)) ret += fun(x+1,y);
    if(valid(x,y+1)) ret += fun(x,y+1);
    return dp[x][y] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&m);
        getchar();

        memset(vv,true,sizeof(vv));

        for(int i=1; i<=n; i++)
        {
            string ss;
            getline(cin,ss);
            //cout << ss << endl;
            stringstream pp(ss);
            int xx,id=0,k=0;
            while(pp>>xx){
                if(k==0)k=xx;
                else{
                    ww[k].push_back(xx);
                    //vv[k][xx]=false;
                }
            }

        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<ww[i].size(); j++){
                vv[i][ww[i][j]] = false;
                //printf("(%d, %d) ",i,ww[i][j]);
            }
            //printf("\n");
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(1,1);

        printf("%d\n",ans);
        if(ks<tt)printf("\n");

        for(int i=0; i<=n; i++)ww[i].clear();
    }
    return 0;
}
