#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bigmod(ll b, ll p, ll m)
{
    ll res=1;
    if(p==1){
        return b;
    }
    if(p%2==0)
    {
        //res = ((bigmod(b,p/2,m)%m)*(bigmod(b,p/2,m)%m)%m);
        res = (bigmod(b,p/2,m)%m);
        res = ((res%m)*(res%m))%m;
    }
    else{
        res = ((bigmod(b,p-1,m)%m)*(b%m)%m);
    }

    return res%m;
}
int main()
{
    ll b,p,m,res;

    while(scanf("%lld%lld%lld",&b,&p,&m)==3)
    {
        if(b==0)
            res=0;
        else if(p==0)
            res=1;
        else
            res = bigmod(b,p,m);
        printf("%lld\n",res);
    }

    return 0;
}
