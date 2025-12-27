#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vv;
map< pair <ll,ll> , ll>dp;
bool flag;
ll a,b;
bool cmp(ll x,ll y)
{
    return x>y;
}
ll GCD(ll m,ll n)
{
    if(n==0)return m;
    return GCD(n,m%n);
}

void DFS(ll x,ll y)
{
    if(flag==true)return;

    if(x>a)return;
    if(y>b)return;
    if(x==a&&y==b){
        flag=true;
        //assert(flag);
        return;
    }

    pair <ll,ll> pp;
    pp = make_pair(x,y);
    if(dp[pp]!=0)return;

    dp[pp]=1;

    ll ret1,ret2,ret3;

    for(int i=0; i<vv.size(); i++)
    {
        ll xx,yy,u1,u2;

        u2 = vv[i]*vv[i];
        u1 = vv[i];

        xx = x*u2; yy = y*u1;
        if(flag==false)DFS(xx,yy);

        xx = x*u1; yy = y*u2;
        if(flag==false)DFS(xx,yy);
    }

}
int main()
{
    ll n;
    scanf("%I64d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d %I64d",&a,&b);

        if(a==1&&b==1)
        {
            printf("Yes\n");
            continue;
        }
        if(a==1&&b!=1)
        {
            printf("No\n");
            continue;
        }
        if(b==1&&a!=1)
        {
            printf("No\n");
            continue;
        }

        ll gcd = GCD(a,b);

        if(gcd==1)
        {
            printf("No\n");
            continue;
        }

        ll sq = sqrt(gcd);

        //cout << "gcd=" << gcd << endl;

        vv.clear();

        for(int i=2; i<=sq; i++)
        {
            if(gcd%i==0)
            {
                vv.push_back(i);
                if(i!=(gcd/i)){
                    vv.push_back(gcd/i);
                }
            }
        }
        vv.push_back(gcd);

        sort(vv.begin(),vv.end(),cmp);
        //cout << vv[0] << endl;
        flag=false;
        dp.clear();

        DFS(1,1);

        if(flag){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}

