/*** Gym100886G - Maximum Product:
Find the number from the range [a,b] which has the maximum product of the digits.
The first line contains two positive integers a and b(1≤a≤b≤10^18).
Print the number with the maximum product of the digits from the range [a,b].
If there are several possible answers, print any one of them.
***/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string sa,sb,res;
ll sz,dp[20][2][2][2];
ll fun(int pos,int choto,int boro,int suru){
    if(pos==sz){
        if(suru) return 1LL;
        else return 0LL;
    }
    if(dp[pos][choto][boro][suru]!=-1) return dp[pos][choto][boro][suru];
    ll ret = 0;
    int lo=0,hi=9;  if(!boro) lo=sa[pos]-'0';  if(!choto)hi=sb[pos]-'0';

    for(ll i=lo; i<=hi; i++){
        if(suru==0&&i==0){
            ret = max(ret,fun(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0)));
        }else{
            ret = max(ret,i*fun(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0)));
        }
    }
    return dp[pos][choto][boro][suru] = ret;
}
void path(int pos,int choto,int boro,int suru){
    if(pos==sz)return; 
    
    ll minn = fun(pos,choto,boro,suru);

    int lo=0,hi=9;  if(!boro) lo=sa[pos]-'0';  if(!choto)hi=sb[pos]-'0';

    for(ll i=lo; i<=hi; i++){
        if(suru==0&&i==0){
            ll ret = fun(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0));
            if(ret==minn){
                path(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0));
                break;
            }
        }else{
            ll ret = i*fun(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0));
            if(ret==minn){
                res+=(i+'0');
                path(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0));
                break;
            }
        }
    }
}
int main(){
    ll a,b; cin>>a>>b; if(a>b)swap(a,b);

    char aa[25], bb[25];
    sprintf(bb,"%lld",b); sb = bb; sz = sb.size();
    sprintf(aa,"%lld",a); 
    int d = sz-strlen(aa);
    sa=""; for(int i=1; i<=d; i++)sa+='0';
    sa += aa;

    memset(dp,-1,sizeof(dp));
    ll ans = fun(0,0,0,0); //cout<<ans<<endl;
    path(0,0,0,0);
    cout<<res<<endl;
}
