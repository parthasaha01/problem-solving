#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;
int ar[20];
ll var, dp[20][2][20];
bool check(int index,int len){
      int id=0, oo[20];
      ll d = var;
      for( ; d!=0 ; id++, d/=10) oo[id] = d%10;
      for(int i=id-1; i>index; i--) d = 10*d+oo[i];
      for(int i=index+((len%2)? 2 : 1); i<len ; i++) d = 10*d+oo[i];
      if(d <= var) return 1;
      return 0;
}
ll fun(int ind, int flag, int len)
{
      if(ind == (len)/2 - 1){
            if(flag && len) return check(ind,len);
            return 1;
      }
      if(!flag && dp[ind][flag][len]!=-1) return dp[ind][flag][len];

      ll res=0,hi = 9;
      if(flag) hi = ar[ind];
      for(int i=0; i<=hi; i++) {
            res += fun(ind-1, flag&&(i==hi), i ? (len==0 ? ind+1 : len): len);
      }
      if(flag) return res;
      return dp[ind][flag][len] = res;
}

ll Solve(ll a){
      var = a; int ind;
      for(ind=0; a!=0; ind++){ ar[ind]= a%10; a/=10; }
      memset(dp,-1,sizeof(dp));
      return fun(ind-1,1,0);
}
int main(){
      int t; scanf("%d",&t);
      for(int ks=1; ks<=t; ks++){
            ll a,b; scanf("%lld%lld",&a,&b); if(a>b) swap(a,b);
            printf("Case %d: %lld\n", ks, Solve(b) - Solve(a-1));
      }
      return 0;
}
