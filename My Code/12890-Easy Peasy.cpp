#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
map<ll,int>mp;
int a[mx];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        mp.clear();

        ll n;
        scanf("%lld",&n);

        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }

        ll sum=0;
        ll p=1;
        ll d=0;

        for(ll r=1; r<=n; r++)
        {
            ll v=a[r];

            if(mp[v]<p)
            {
                mp[v]=r;
            }
            else
            {
                d=r-p;
                sum+=(d*(d+1))/2;

                d=r-mp[v]-1;
                sum-=(d*(d+1))/2;

                p=mp[v]+1;
                mp[v]=r;
            }
        }

        d=(n-p)+1;
        sum+=(d*(d+1))/2;

        printf("%lld\n",sum);
    }

    return 0;
}

/*
3
3
1 2 1
5
1 2 3 1 2
11
1 2 3 4 3 5 1 1 8 7 4
*/
