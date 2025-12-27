#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int sz;
int dp[40][2][2][50];
int fun(int pos,int choto,int pre,int cnt)
{
    if(pos==sz){
        return 0;
    }

    if(dp[pos][choto][pre][cnt] != -1) return dp[pos][choto][pre][cnt];

    int lo=0,hi=1;
    if(!choto)hi=s[pos]-'0';
    int ret = 0;

    for(int i=lo; i<=hi; i++){

    }
    return dp[pos][choto][pre][cnt]=ret;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n; scanf("%lld",&n);
        s="";
        if(n==0) s+='0';
        while(n!=0){
            int r = n%2;
            s+=r+'0';
            n/=2;
        }
        reverse(s.begin(),s.end());
        sz = s.size();
        //cout << s << endl;
        int ans = fun(0,0,0,0);

    }
}
