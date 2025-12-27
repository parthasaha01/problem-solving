#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
string s,t;
int n,d;
map< pair<int,int>, int >dp,vs;
int fun(int pos,int sum)
{
    if(pos==n){
        if(sum==d)return 1;
        else return 0;
    }

    pii p; p.first = pos; p.second = sum;

    if(vs[p]!=0)return dp[p];
    vs[p] = 1;

    int ret = 0;
    if(t[pos]=='+')ret += fun(pos+1,sum+1);
    if(t[pos]=='-')ret += fun(pos+1,sum-1);
    if(t[pos]=='?'){
        ret += fun(pos+1,sum+1);
        ret += fun(pos+1,sum-1);
    }

    return dp[p] = ret;
}
int main()
{
    cin>>s>>t;
    n = s.size();

    for(int i=0; i<n; i++){
        if(s[i]=='+')d+=1;
        if(s[i]=='-')d-=1;
    }

    int c=0;
    for(int i=0; i<n; i++){
        if(t[i]=='?')c++;
    }

    int tot = (1<<c);
    int way = fun(0,0);

    double ans = (double)way / (double)tot;
    printf("%.12f\n",ans);

    return 0;
}
