#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
//#define MOD 100000000000031LL
map<ll,ll>mp;
ll sum[100005];
void calc()
{
    sum[0]=1;
    for(int i=1; i<=100002; i++){
        sum[i] = (sum[i-1]*31LL);
       // sum[i] %= MOD;
    }
}

int fun1(ll pos, ll hh)
{
    ll ret = 0;
    for(int v='a'; v<='z'; v++)
    {
        ll gg = hh;
        gg += (v*sum[pos]);
       // gg %= MOD;
        if(mp.find(gg)!=mp.end()){
            int f = fun1(pos+1,gg);
            ret |= f;
        }
    }

    return ret^1;
}
int fun2(ll pos, ll hh)
{
    ll ret = 0;
    ll ch = 1;

    for(int v='a'; v<='z'; v++)
    {
        ll gg = hh;
        gg += (v*sum[pos]);
        //gg %= MOD;
        if(mp.find(gg)!=mp.end()){
            ch = 0;
            int f = fun2(pos+1,gg);
            ret |= f;
        }
    }
    ret |= ch;

    return ret^1;
}
int main()
{
    calc();

    ios::sync_with_stdio(false);
    cin.tie(0); // warning: we can not use both cin and scanf


    int n,k;
    cin>>n>>k;
    string s;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        ll hh = 0;
        for(int j=0; j<s.size(); j++)
        {
            hh += (s[j]*sum[j]);

            if(mp.find(hh)!=mp.end()){
                //
            }
            else{
                mp[hh] = 1;
            }
        }
    }

    long long win=!fun1(0,0);
    long long lose=!fun2(0,0);



    if(!win) printf("Second\n");
    else if(win&&lose) printf("First\n");
    else{
        if(k&1) printf("First\n");
        else printf("Second\n");
    }

    return 0;
}
