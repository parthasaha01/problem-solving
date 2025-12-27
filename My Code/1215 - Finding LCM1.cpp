#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return (a/gcd(a,b))*b;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll a,b,Labc;
        scanf("%lld%lld%lld",&a,&b,&Labc);
        ll Lab=lcm(a,b);

        if(Labc%Lab!=0){
            printf("Case %d: impossible\n",ks);
        }
        else{
            ll c=Labc/Lab;
            ll x=gcd(Lab,c);

            while(x!=1)
            {
                c*=x;
                Lab/=x;
                x=gcd(Lab,c);
            }

            printf("Case %d: %lld\n",ks,c);
        }
    }

    return 0;
}

