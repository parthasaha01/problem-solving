#include<bits/stdc++.h>
using namespace std;
int fr[15];
vector<int>a;
int n,m,flag;
int dp[14][10002][2];
string s;
int fun(int p,int v,int f)
{
    //if(flag)return 0;
    if(v==0 && p>0 && f) {
        //flag = 1;
        return 0;
    }

    if(p==14)return 100000;

    if(dp[p][v][f]!=-1)return dp[p][v][f];

    int ret = 100000;
    for(int i=0; i<a.size(); i++){
        ret = min(ret,1+fun(p+1,((v*10)+a[i])%n,f|(a[i]>0)));
    }
    return dp[p][v][f] = ret;
}
void path(int p,int v,int f)
{
    if(v==0 && p>0 && f)return;
    if(p==14)return;

    int ret = fun(p,v,f);

    for(int i=0; i<a.size(); i++){
        int ff = 1+fun(p+1,((v*10)+a[i])%n,f|(a[i]>0));
        if(ff==ret){
            if(f==1 || (a[i]>0))s += a[i]+'0';
            path(p+1,((v*10)+a[i])%n,f|(a[i]>0));
            break;
        }
    }
}
int main()
{
    int ks=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(fr,0,sizeof(fr));
        for(int i=1; i<=m; i++){
            int x; scanf("%d",&x);
            fr[x] = 1;
        }

        a.clear();
        for(int i=0; i<10; i++){
            if(fr[i]==0)a.push_back(i);
        }

        flag = 0;
        memset(dp,-1,sizeof(dp));
        int f = fun(0,0,0);
        s="";

        if(f<100000){
            path(0,0,0);
            printf("Case %d: ",++ks);
            cout << s << endl;
        }
        else{
            printf("Case %d: -1\n",++ks);
        }
    }
    return 0;
}
