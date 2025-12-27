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

        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
        }

        ll sum=0;

        ll p=1;

        for(ll r=1; r<=n; r++)
        {
            ll v=a[r];

            if(mp[v]==0)
            {
                mp[v]=1;
            }
            else
            {

                for(ll i=p; i<=r; i++)
                {
                    ll u=a[i];

                    if(u!=v)
                    {
                        sum+=(r-i);
                        mp[u]=0;
                    }
                    else
                    {
                        sum+=(r-i);
                        p=i+1;
                        break;
                    }
                }
            }
        }

        ll d=(n-p)+1;
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
