#include<bits/stdc++.h>
using namespace std;
vector<int>vv[35];
int n,k,dp[35][205],s[205];
int lf[205][205],rg[205][205],mn[205][205];
int fun(int x, int b)
{
    if(b>n){
        if(x==0)return 0;
        else return 1000000000;
    }
    if(x<=0)return 1000000000;

    if(dp[x][b]!=-1)return dp[x][b];

    int ret = 1000000000;

    for(int e=b; e<=n; e++)
    {
        int p = mn[b][e];
        int v = lf[p][b]+rg[p][e];
        ret = min(ret,v+fun(x-1,e+1));
    }
    return dp[x][b] = ret;
}
void path(int x, int b,int d)
{
    if(b>n)return;
    if(x<=0)return;

    int res = fun(x,b);

    for(int e=b; e<=n; e++)
    {
        int p = mn[b][e];
        int v = lf[p][b]+rg[p][e];
        int ret = v+fun(x-1,e+1);

        if(ret==res)
        {
            vv[d].push_back(p);
            vv[d].push_back(b);
            vv[d].push_back(e);
            path(x-1,e+1,d+1);
            break;
        }
    }
}
int main()
{
    int ks=0;

    while(scanf("%d%d",&n,&k))
    {
        if(!n && !k)break;

        for(int i=1; i<=n; i++)scanf("%d",&s[i]);

        for(int i=1; i<=n; i++)
        {
            lf[i][i]=0;
            for(int j=i-1; j>=1; j--)
            {
                lf[i][j] = lf[i][j+1] + (s[i]-s[j]);
            }

            rg[i][i]=0;
            for(int j=i+1; j<=n; j++)
            {
                rg[i][j] = rg[i][j-1] + (s[j]-s[i]);
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                int x = 1000000000;
                int p = 0;

                for(int k=i; k<=j; k++)
                {
                    int v = lf[k][i]+rg[k][j];
                    if(v<x)
                    {
                        x = v;
                        p = k;
                    }
                }

                mn[i][j] = p;
            }
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(k,1);
        path(k,1,1);

        printf("Chain %d\n",++ks);

        for(int i=1; i<=k; i++)
        {
            if(vv[i][1]==vv[i][2]){
                printf("Depot %d at restaurant %d serves restaurant %d\n",i,vv[i][0],vv[i][1]);
            }
            else{
                printf("Depot %d at restaurant %d serves restaurants %d to %d\n",i,vv[i][0],vv[i][1],vv[i][2]);
            }
        }

        printf("Total distance sum = %d\n",ans);
        printf("\n");

        for(int i=0; i<=k; i++)vv[i].clear();
    }

    return 0;
}

/*
6 3
5
6
12
19
20
27
*/
