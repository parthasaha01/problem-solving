#include<bits/stdc++.h>
using namespace std;
#define mx 500000
int n,a[mx+5],p[mx+5];
//int dp[mx+2][1025];
map<int,map<int,int> >dp;
map<int,map<int,int> >vs;
int mp[1025];
int fun(int pos,int v)
{
    if(pos==n)return v;

    if(vs[pos][v]!=0)return dp[pos][v];
    vs[pos][v]=1;

    int ret = 0;

    if(p[pos]==1){
        ret = fun(pos+1,(v&a[pos]));
    }
    else if(p[pos]==2){
        ret = fun(pos+1,(v|a[pos]));
    }
    else{
        ret = fun(pos+1,(v^a[pos]));
    }

    return dp[pos][v]=ret;
}
int main()
{
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        char ch; int x;
        getchar();
        scanf("%c %d",&ch,&x);
        //printf("%c %d\n",ch,x);
        if(ch=='&')p[i]=1;
        else if(ch=='|')p[i]=2;
        else p[i]=3;

        a[i]=x;
    }

    //memset(dp,-1,sizeof(dp));

    for(int i=0; i<1024; i++)
    {
        int v = fun(0,i);
        mp[i]=v;
        printf("i=%d v=%d\n",i,v);
    }




}
