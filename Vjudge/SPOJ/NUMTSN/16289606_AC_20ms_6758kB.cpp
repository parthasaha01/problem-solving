#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
int dp[51][2][2][17][17][17];
string LB,UB;
int fun(int pos, int boro, int choto, int three, int six, int nine){
    if(three>16 || six>16 || nine>16)return 0LL;
    if(pos==51){
        if(three>0 && three==six && six==nine) return 1LL;
        return 0LL;
    }

    int &ret = dp[pos][boro][choto][three][six][nine];
    if(ret!=-1 && choto && boro) return ret;

    int lo = 0, hi=9;
    if(boro==0) lo = LB[pos]-'0';
    if(choto==0)hi = UB[pos]-'0';
    ret = 0;
    for(int i=lo; i<=hi; i++){
        ret += fun(pos+1, boro|(i>lo), choto|(i<hi), three+(i==3), six+(i==6), nine+(i==9));
        ret %= MOD;
    }
    return ret;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        cin >> LB;
        string p;
        int d = 51-LB.size();
        for(int i=1; i<=d; i++)p+="0";
        LB = p+LB;

        cin >> UB;
        string q;
        int c = 51-UB.size();
        for(int i=1; i<=c; i++)q+="0";
        UB = q+UB;

        int ans = fun(0,0,0,0,0,0);
        cout << ans << endl;
    }
    return 0;
}