#include<bits/stdc++.h>
using namespace std;
#define ll long long
string bg,ed;
ll sz,dp[65][2][2][1050];
ll bb,lf,rg;
int settoggle(int mask,int pos)
{
    return mask ^ (1<<pos);
}
void convbg(ll b,ll v)
{
    bg="";
    while(v!=0)
    {
        ll r = v%b;
        bg += r+'0';
        v/=b;
    }
    reverse(bg.begin(),bg.end());
}
void conved(ll b,ll v)
{
    ed="";
    while(v!=0)
    {
        ll r = v%b;
        ed += r+'0';
        v/=b;
    }
    reverse(ed.begin(),ed.end());
}
ll fun(int pos,int choto,int suru,int mask)
{
    if(pos==sz){
        if(mask==0)return 1LL;
        return 0;
    }

    if(dp[pos][choto][suru][mask]!=-1) return dp[pos][choto][suru][mask];

    ll ret = 0;
    int lo=0,hi=bb-1;
    if(!choto)hi = ed[pos]-'0';

    for(int i=lo; i<=hi; i++){

        int next_mask=mask;
        if(i>0 || suru==1)next_mask = settoggle(mask,i);

        ret += fun(pos+1,choto|(i<hi),suru|(i>0),next_mask);
    }
    return dp[pos][choto][suru][mask] = ret;
}
int main()
{
    ll tt;
    scanf("%I64d",&tt);
    memset(dp,-1,sizeof(dp));
    for(int ks=1; ks<=tt; ks++)
    {

        scanf("%I64d %I64d %I64d",&bb,&lf,&rg);

        if(lf>rg)swap(lf,rg);

        convbg(bb,lf);
        conved(bb,rg);

        int lb=bg.size();
        int le=ed.size();
        int ld = le-lb;
        for(int i=1; i<=ld; i++)bg = "0"+bg;
        lb=bg.size();
        sz = le;
        //cout << bg << " " << ed << endl;
        ll ans1 = fun(0,0,0,0);

        printf("%I64d\n",ans);
    }

    return 0;
}
