#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll dp[1002][2][1002];
ll wp[1005];
int k,len;
string s;
int gh;
ll call(int pos, int choto, int cnt)
{
    if(pos==len){
       // gh++;
        //cout << p << " " << cnt << " " << wp[cnt] << endl;
        if(wp[cnt]==k-1)return 1LL;
        else return 0LL;
    }

    if(dp[pos][choto][cnt]!=-1)
        return dp[pos][choto][cnt];

    ll ret=0, next_choto;


    int  low=0, high=1;
    if(choto==0) high=s[pos]-'0';

    for(int i=low; i<=high; i++)
    {
        if(choto==0)
        {
            if(i==high) next_choto=0;
            else next_choto=1;
        }
        else
            next_choto=1;

        //string q;
        //q+=p;
        //q+=i+'0';

        if(i==0) ret += call(pos+1,next_choto,cnt);
        else ret += call(pos+1,next_choto,cnt+1);

        ret %= mod;

    }

    return dp[pos][choto][cnt]=ret%mod;

}
int main()
{
    cin>>s;
    cin>>k;

    wp[1] = 0;

    for(int i=2; i<=1001; i++)
    {
        int x = __builtin_popcount(i);
        wp[i] = wp[x]+1;
    }

    if(k==0){
        printf("1\n");
        return 0;
    }

    len = s.size();
    memset(dp,-1,sizeof(dp));
    ll ans = call(0,0,0);
    if(k==1)ans-=2;
    cout << ans << endl;
    //cout << gh << endl;

    return 0;
}

