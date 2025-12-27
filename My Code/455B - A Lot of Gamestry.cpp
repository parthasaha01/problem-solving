#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD1 999999999999989LL
#define MOD2 100000000000031LL
map<ll,ll>mp;
map<ll,ll>sp;
ll sum[100005],cum[100005];
void calc()
{
    sum[0]=1;
    cum[0]=1;
    for(int i=1; i<=100002; i++){
        sum[i] = (sum[i-1]*31LL);
        sum[i] %= MOD1;
        cum[i] = (cum[i-1]*43LL);
        cum[i] %= MOD2;
    }
}

int fun1(ll pos, ll hh, ll pp)
{
    ll ret = 0;
    bool flag = false;
    for(int v='a'; v<='z'; v++)
    {
        ll gg = hh;
        gg += (v*sum[pos]);
        gg %= MOD1;
        ll qq = pp;
        qq += (v*cum[pos]);
        qq %= MOD2;
        if(mp.find(gg)!=mp.end()){
            if(sp.find(qq)!=sp.end()){
                flag = true;
                int f = fun1(pos+1,gg,qq);
                ret |= (1^f);
            }
        }
    }

    if(flag==false)ret = 1;

//    cout << pos << " " << s  << " " << ret << endl;

    return ret;

    //return ret;
}
int fun2(ll pos, ll hh,ll pp)
{
    //cout << pos << " " << s << endl;
    ll ret = 0;
    bool flag = false;
    ll cnt = 0;
    ll loss = 0;
    for(int v='a'; v<='z'; v++)
    {
        ll gg = hh;
        gg += (v*sum[pos]);
        gg %= MOD1;
        ll qq = pp;
        qq += (v*cum[pos]);
        qq %= MOD2;
        if(mp.find(gg)!=mp.end()){
            if(sp.find(qq)!= sp.end()){
                flag = true;
                cnt++;
                int f = fun2(pos+1,gg,qq);
                if(f==0)loss++;
                ret |= (1^f);
            }
        }
    }

    if(flag==false)ret = 1;

    if(pos==0){
       // cout << cnt << " " << loss << endl;
        if(cnt==loss)return 1;
        else return 0;
    }

   //cout << pos << " " << s  << " " << ret << endl;

    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    calc();

    int n,k;
    cin>>n>>k;
    string s;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        ll hh = 0;
        ll pp = 0;
        for(int j=0; j<s.size(); j++)
        {
            hh += (s[j]*sum[j]);
            pp += (s[j]*cum[j]);
            hh %= MOD1;
            pp %= MOD2;

            if(mp.find(hh)!=mp.end()){
                //
            }
            else{
                mp[hh] = 1;
            }

            if(sp.find(pp)!=sp.end()){
                //
            }
            else{
                sp[pp] = 1;
            }
        }
    }

    int win = fun1(0,0,0);

    if(win==0){
        if(k%2==1)printf("First\n");
        else printf("Second\n");
    }
    else{
        int loss = fun2(0,0,0);
        //cout << "loss=" << loss << endl;

        if(loss==1)printf("Second\n");
        else printf("First\n");
    }

    return 0;
}
/*
5 6
abas
dsfdf
abacaba
dartsidius
kolobok

4 2
aaaa
bbbb
ccccc
dumbavumba
*/

