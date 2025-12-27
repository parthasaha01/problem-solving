#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN = 4;
const LL INF = 1000000000000000005LL;
LL dp[5][1030][2];
vector<LL>vv;
string s;
LL fun(int pos,int mask,int suru,string s)
{
    if(pos==MAXN){
        if(suru==0){
            return 0LL;
        }
        string ss;
        int bit=0,MAXX=0;
        for(int i=0; i<10; i++){
            if(mask&(1<<i)){
                ss += '1';
                MAXX = max(MAXX,i);
                bit++;
            }
            else{
                ss += '0';
            }
        }

        reverse(ss.begin(),ss.end());

        //cout << mask << " " << ss << " " << s << " " <<  bit << " " << MAXX << endl;
        //getchar();
        if(bit==MAXX){
            LL v = 0;
            for(int i=0; i<s.size(); i++){
                LL d = s[i]-'0';
                v = (v*10)+d;
            }
            vv.push_back(v);
            return 1LL;
        }
        return 0LL;
    }

    if(dp[pos][mask][suru]!=-1)return dp[pos][mask][suru];

    LL ret = 0LL;
    for(int i=0; i<10; i++){
        string ss = s;
        ss += i+'0';
        if(i==0 && suru==0)
            ret += fun(pos+1,mask,suru|(i>0),ss);
        else
            ret += fun(pos+1,mask|(1<<i),suru|(i>0),ss);
    }

    return dp[pos][mask][suru] = ret;
}
void path(int pos,int mask,int suru,LL nth)
{
    if(pos==MAXN)return;
    LL ret = 0,res=0;
    for(int i=0; i<10; i++){
        if(i==0 && suru==0)
            ret += fun(pos+1,mask,suru|(i>0),"");
        else
            ret += fun(pos+1,mask|(1<<i),suru|(i>0),"");

        //cout << i << " " << ret << " " << res << " " << nth << " " << s <<  endl;
       // getchar();
        if(ret>=nth){
            s += i+'0';
            if(i==0 && suru==0)
                path(pos+1,mask,suru|(i>0),nth-res);
            else
                path(pos+1,mask|(1<<i),suru|(i>0),nth-res);
            break;
        }
        res = ret;
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    fun(0,0,0,"");

    int tt; scanf("%d",&tt);
    LL ans = 0;

    for(LL i=1; i<=30; i++){
        s = "";
        path(0,0,0,i);
        cout << i << "-->" << s << endl;
    }
//    for(int i=0; i<20; i++){
//        cout << vv[i] << " ";
//    }
//    cout << endl;

    for(int ks=1; ks<=tt; ks++)
    {
        LL n; scanf("%lld",&n);
        LL lo = 1, hi = n;
        while(lo<=hi)
        {
            LL md = (lo+hi)/2;

            s = "";
            path(0,0,0,md);
            LL v = 0;
            for(int i=0; i<s.size(); i++){
                LL d = s[i]-'0';
                v = (v*10)+d;
            }
            cout << md << " " << s << endl;
            if(v<=n){
                ans = md;
                lo = md+1;
            }
            else{
                hi = md-1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

