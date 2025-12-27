#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
int dp[50][17][17][17];
string s;
int fun(int pos, int three, int six, int nine){
    if(three>16 || six>16 || nine>16)return 0;
    if(pos==(int)s.size()){
        if(three==six && six==nine && three>0){
            return 1LL;
        }
        return 0LL;
    }

    if(dp[pos][three][six][nine]!=-1)
        return dp[pos][three][six][nine];
    int lo = 0, hi=9;
    int ret = 0;
    for(int i=lo; i<=hi; i++){
        int nthree = three, nsix = six, nnine = nine;
        if(i==3) nthree++;
        if(i==6) nsix++;
        if(i==9) nnine++;
        ret += fun(pos+1, nthree, nsix, nnine);
        ret %= MOD;
    }
    return dp[pos][three][six][nine] = ret;
}
bool check(){
    int three=0, six = 0, nine = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='3')three++;
        if(s[i]=='6')six++;
        if(s[i]=='9')nine++;
    }
    if(three>0 && three==six && six==nine)return true;
    return false;
}
int main(){
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=50; i++)s+="9";
    int x = fun(0,0,0,0);
    //cout << x << endl;

    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        cin>>s;
//        string p;
//        int d = 51-s.size();
//        for(int i=1; i<=d; i++)p+="0";
//        s = p+s;
//        cout << s << endl;
        memset(dp,-1,sizeof(dp));
        int y = fun(0,0,0,0);
        if(check()){
            y--;
            if(y<0) y = (y+MOD)%MOD;
        }
        //cout << y << endl;

        cin>>s;

//        string q="";
//        int c = 51-s.size();
//        for(int i=1; i<=c; i++)q+="0";
//        s = q+s;
//        cout << s << endl;

        memset(dp,-1,sizeof(dp));
        int x = fun(0,0,0,0);
        //cout << x << endl;

        int ans = x-y;
        if(ans<0) ans = (ans+MOD)%MOD;
        cout << ans << endl;
    }
    return 0;
}
