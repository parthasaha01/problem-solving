#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,nn,sv,su;
ll w,a[40];
vector<ll>vv,uu;
void fun1(int pos,ll sum)
{
    if(pos==nn){ vv.push_back(sum); return; }

    fun1(pos+1,sum);
    fun1(pos+1,sum+a[pos]);
}
void fun2(int pos,ll sum)
{
    if(pos==n){ uu.push_back(sum); return; }

    fun2(pos+1,sum);
    fun2(pos+1,sum+a[pos]);
}
int check(ll v)
{
    int lo=0; int hi=su-1;
    int cnt=-1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(uu[md]<=v){
            lo=md+1;
            cnt=md;
        }
        else hi=md-1;
    }
    return cnt+1;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        vv.clear(); uu.clear();

        scanf("%d%lld",&n,&w);
        for(int i=0; i<n; i++)scanf("%lld",&a[i]);
        sort(a,a+n);
        nn = n/2;

        fun1(0,0);
        fun2(nn,0);

        sort(uu.begin(),uu.end());

        sv = vv.size();
        su = uu.size();

        int ans = 0;
        for(int i=0; i<sv; i++)
        {
            ll v = vv[i];
            int cnt = check(w-v);
            ans += cnt;
        }
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
