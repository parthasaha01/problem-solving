#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
int dp[51][18][18][18][2];
string s;
int fun(int pos, int three, int six, int nine,int choto){
    if(three>16 || six>16 || nine>16)return 0;
    if(pos==(int)s.size()){
        if(three==six && six==nine && three>0){
            //cout << p << endl;
            return 1LL;
        }
        return 0LL;
    }

    if(dp[pos][three][six][nine][choto]!=-1)
        return dp[pos][three][six][nine][choto];
    int lo = 0, hi=9;
    if(choto==0)hi = s[pos]-'0';
    int ret = 0;
    for(int i=lo; i<=hi; i++){
        int nthree = three, nsix = six, nnine = nine;
        if(i==3) nthree++;
        if(i==6) nsix++;
        if(i==9) nnine++;
        //string q = p;
        //q += i+'0';
        //ret += fun(pos+1, nthree, nsix, nnine, choto | (i<hi), q);
        ret += fun(pos+1, nthree, nsix, nnine, choto | (i<hi));
        ret %= MOD;
    }
    return dp[pos][three][six][nine][choto] = ret;
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
//    memset(dp,-1,sizeof(dp));
//    s+="1";
//    for(int i=1; i<=50; i++)s+="0";
//
//    //s = "4325667";
//    //int x = fun(0,0,0,0,0,"");
//    int x = fun(0,0,0,0,0);
//    cout << x << endl;

    //memset(dp,-1,sizeof(dp));
    //s = "4234";
    //int y = fun(0,0,0,0,0,"");
    //int y = fun(0,0,0,0,0);

    //cout << y << endl;
    //cout << x-y << endl;

    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        cin>>s;
//        string p;
//        int d = 51-s.size();
//        for(int i=1; i<=d; i++)p+="0";
//        s = p+s;
//        cout << s << endl;

        memset(dp,-1,sizeof(dp));
        int y = fun(0,0,0,0,0);
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
        int x = fun(0,0,0,0,0);

        //cout << x << endl;

        int ans = x-y;
        if(ans<0) ans = (ans+MOD)%MOD;
        cout << ans << endl;
    }
    return 0;
}

