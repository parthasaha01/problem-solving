#include<bits/stdc++.h>
using namespace std;
#define inf -100000000
int n,ba,bo,fi,dp[105][10][10][10];
vector<int>u,v,w;
struct dt{
    int x,y,z;
}st[105];
int fun(int p,int q,int r,int s)
{
    if(p==n+1){
        if(q==ba&&r==bo&&s==fi)return 0;
        return inf;
    }

    if(dp[p][q][r][s] != -1)return dp[p][q][r][s];

    int ret=inf,ret1=inf,ret2=inf,ret3=inf,ret4=inf;
    double x,y,z;
    x=st[p].x; y=st[p].y; z=st[p].z;


    if(q<ba)ret1  = (int)round(0.8*x+0.2*z)       + fun(p+1,q+1,r,s);
    if(r<bo)ret2  = (int)round(0.7*y+0.1*x+0.2*z) + fun(p+1,q,r+1,s);
    if(s<fi)ret3  = (int)round(0.4*x+0.4*y+0.2*z) + fun(p+1,q,r,s+1);
    ret4  = fun(p+1,q,r,s);

    ret = max(ret1,max(ret2,max(ret3,ret4)));
    return dp[p][q][r][s] = ret;
}
void path(int p,int q,int r,int s)
{
    if(p==n+1)return;

    int ret = fun(p,q,r,s);

    int ret1=inf,ret2=inf,ret3=inf,ret4=inf;
    double x,y,z;
    x=st[p].x; y=st[p].y; z=st[p].z;


    if(q<ba)ret1  = (int)round(0.8*x+0.2*z)       + fun(p+1,q+1,r,s);
    if(r<bo)ret2  = (int)round(0.7*y+0.1*x+0.2*z) + fun(p+1,q,r+1,s);
    if(s<fi)ret3  = (int)round(0.4*x+0.4*y+0.2*z) + fun(p+1,q,r,s+1);
    ret4  = fun(p+1,q,r,s);

    if(ret==ret1){
        if(ret1>=0)u.push_back(p);
        path(p+1,q+1,r,s);
    }
    else if(ret==ret2){
        if(ret2>=0)v.push_back(p);
        path(p+1,q,r+1,s);
    }
    else if(ret==ret3){
        if(ret3>=0)w.push_back(p);
        path(p+1,q,r,s+1);
    }
    else{
        path(p+1,q,r,s);
    }
}
int main()
{
    int ks = 0;

    while(scanf("%d",&n) && n)
    {
        for(int i=1; i<=n; i++)
        {
            int x,y,z; scanf("%d%d%d",&x,&y,&z);
            st[i].x=x;
            st[i].y=y;
            st[i].z=z;
        }
        scanf("%d%d%d",&ba,&bo,&fi);
        memset(dp,-1,sizeof(dp));
        int ans = fun(1,0,0,0);

//        double res = (double)ans;
//        printf("res1=%lf\n",res);
//        res = round(res);
//        printf("res2=%lf\n",res);
//        ans = res;
//        printf("ans=%d\n",ans);

        u.clear();v.clear();w.clear();
        path(1,0,0,0);

        if(ks>0)printf("\n");
        printf("Team #%d\n",++ks);
        printf("Maximum Effective Score = %d\n",ans);

        //if(u.size()!=0){
            printf("Batsmen :");
            for(int i=0; i<u.size(); i++)printf(" %d",u[i]);
            printf("\n");
        //}

        //if(v.size()!=0){
            printf("Bowlers :");
            for(int i=0; i<v.size(); i++)printf(" %d",v[i]);
            printf("\n");
        //}

        //if(w.size()!=0){
            printf("All-rounders :");
            for(int i=0; i<w.size(); i++)printf(" %d",w[i]);
            printf("\n");
        //}
    }
    return 0;
}

/*

15
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
88 29 83
30 4 7
66 15 18
20 93 1
11 74 98
20 89 40
58 24 35
6 3 1

*/
