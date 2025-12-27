#include<cstdio>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define mx 100005
#define inf 1000000
int dp[101][400025];
bool vs[101][200025];
bool ok[101][200025];
bool fp[101][200025];
int sm[101],fa[101],n;
bool fun1(int pos,int smart)
{
    if(pos==n){
        if(smart<mx)return ok[pos][smart] = false;
        return ok[pos][smart] = true;
    }

    if(vs[pos][smart]==true)return ok[pos][smart];
    vs[pos][smart]=true;

    bool p1 = fun1(pos+1,smart);
    bool p2 = fun1(pos+1,smart+sm[pos]);

    //printf("f1 pos=%d smart=%d p1=%d p2=%d\n",pos,smart,p1,p2);

    return ok[pos][smart] = p1|p2;
}
bool fun2(int pos,int fair,int smart)
{
    if(pos==n){
        if(fair<mx)return fp[pos][fair] = false;
        return fp[pos][fair] = true;
    }

    if(vs[pos][fair]==true)return fp[pos][fair];
    vs[pos][fair]=true;

    bool p1 = ok[pos+1][smart];
    bool p2 = ok[pos+1][smart+sm[pos]];

    //printf("f2 pos=%d fair=%d p1=%d p2=%d\n",pos,fair,p1,p2);

    bool q1=false,q2=false;

    if(p1==true){
        q1 = fun2(pos+1,fair,smart);
    }
    if(p2==true){
        q2 = fun2(pos+1,fair+fa[pos],smart+sm[pos]);
    }

    //printf("f2 pos=%d fair=%d q1=%d q2=%d\n",pos,fair,q1,q2);

    return fp[pos][fair] = q1|q2;
}
int fun(int pos,int sum,int fair)
{
    if(pos==n)return sum;

    if(dp[pos][sum]!=-1)return dp[pos][sum];

    bool p1 = fp[pos+1][fair];
    bool p2 = fp[pos+1][fair+fa[pos]];

    //printf("pos=%d fair=%d p1=%d p2=%d\n",pos,fair,p1,p2);
    int ret1 = 0, ret2=0;

    if(p1==true){
        ret1 = fun(pos+1,sum,fair);
    }
    if(p2==true){
        ret2 = fun(pos+1,sum+sm[pos]+fa[pos],fair+fa[pos]);
    }

    return dp[pos][sum] = max(ret1,ret2);
}
int main()
{
    scanf("%d",&n);
    int k=n;
    n=0;
    for(int i=0; i<k; i++){
        int x,y; scanf("%d%d",&x,&y);
        if(x>0 || y>0){
            sm[n]=x, fa[n]=y;
            n++;
        }
    }

    //printf("n=%d\n",n);

//    memset(dp,-1,sizeof(dp));
//    for(int i=0; i<5; i++){
//        for(int j=0; j<5; j++){
//            printf("(%d %d) ",dp[i][j].first,dp[i][j].second);
//        }
//        printf("\n");
//    }

    bool f1 = fun1(0,mx);
    memset(vs,false,sizeof(vs));
    bool f2 = fun2(0,mx,mx);
    memset(dp,-1,sizeof(dp));
    int maxx = fun(0,2*mx,mx);
    //if(ans.first<0 || ans.second<0)maxx=0;
    printf("%d\n",maxx-2*mx);

    return 0;
}

/*
4
-2 4
-5 -6
-5 -7
2 -4
*/
