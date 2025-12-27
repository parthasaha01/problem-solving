#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[11][65][1030][2];
int a[] = {0,0,1,2,3,4,5,6,7,8,9};
string s;
int SIZE[] = {0,0,62,41,32,28,26,24,22,21,20};

ll fun(int b,int p,int m,int f,string ss)
{
    if(p>SIZE[b]){
        //cout << ss << endl;
        //printf("f=%d m=%d b=%d\n\n",f,m,b);
        //getchar();
        if(f==0)return 0LL;
        if(m==0)return 1LL;
        else return 0LL;
    }

    if(dp[b][p][m][f] != -1)return dp[b][p][m][f];
    //getchar();

    ll ret = 0;
    for(int i=0; i<=a[b]; i++){
        string hh = ss;
        hh += i+'0';
        if(i==0 && f==0) ret += fun(b,p+1,m,f,hh);
        else ret += fun(b,p+1,m^(1<<i),f|(i>0),hh);
    }
    //cout << ss << endl;
   // printf("b=%d p=%d m=%d f=%d dp=%lld\n\n",b,p,m,f,ret);
    return dp[b][p][m][f] = ret;
}
ll go(int b,int p,int m,int f,int c,string ss)
{
    if(p>SIZE[b]){
        if(f && m==0)return 1LL;
        else return 0LL;
    }

   // cout << ss << endl;
    //cout << s << endl;
    //if(c) printf("b=%d p=%d m=%d f=%d c=%d dp=%lld\n\n",b,p,m,f,c,dp[b][p][m][f]);
    //else  printf("b=%d p=%d m=%d f=%d c=%d\n\n",b,p,m,f,c);
    //getchar();

    if(c)return dp[b][p][m][f];

    int lo = 0;
    int hi = s[p]-'0';

    ll ret = 0;
    for(int i=lo; i<=hi; i++){
        string hh = ss;
        hh += i+'0';
        if(i==0 && f==0){
            ret += go(b,p+1,m,f,c|(i<hi),hh);
        }
        else{
           // printf("***i=%d b=%d p=%d m=%d f=%d c=%d\n\n",i,b,p,m,f,c);
            ret += go(b,p+1,m^(1<<i),f|(i>0),c|(i<hi),hh);
        }
    }

    return ret;
}
string getString(ll b,ll n)
{
    string ss;
    while(n!=0)
    {
        int r = n%b;
        n /= b;
        ss += r+'0';
    }

    int p = SIZE[b]-ss.size();
    for(int i=0; i<=p; i++){
        ss+='0';
    }
    reverse(ss.begin(),ss.end());
    return ss;
}
ll solve(ll b,ll l,ll r)
{
    ll ans = 0;
//    s = "";
   // string s;
    s = getString(b,r);
    ans += go(b,0,0,0,0,"");
    //cout << s << " " << ans << endl;
    if(l>1){
//        s = "";
        s = getString(b,--l);
        ll x = go(b,0,0,0,0,"");
        //cout << s << " " << x << endl;
        //ans -= go(b,0,0,0,0,"");
        ans -= x;
    }
    return ans;
}
int main()
{
   //cout <<  getString(8,75864) << endl;

    memset(dp,-1,sizeof(dp));
    for(int b=2; b<=10; b++){
        fun(b,0,0,0,"");
    }
    int q; scanf("%d",&q);
    while(q--)
    {
        ll b,l,r; scanf("%I64d %I64d %I64d",&b,&l,&r);

        ll ans = solve(b,l,r);

        printf("%I64d\n",ans);
    }
    return 0;
}
/*
10
4 108 114
5 30 155
8 193 197
9 71 169
2 163 166
8 120 144
8 22 151
4 21 166
2 46 127
8 38 51

0
3
0
1
3
0
5
16
9
1


*/
