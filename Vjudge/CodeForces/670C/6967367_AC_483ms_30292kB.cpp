#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 200005
ll n,m,a[mx],b[mx],c[mx];
int main()
{
    while(scanf("%I64d",&n)==1)
    {
        map<ll,ll>mp;

        for(ll i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
            mp[a[i]]++;
        }

        scanf("%I64d",&m);

        for(ll i=1; i<=m; i++)
        {
            scanf("%I64d",&b[i]);
        }
        for(ll i=1; i<=m; i++)
        {
            scanf("%I64d",&c[i]);
        }

        ll ad,sb,pl,st,maxpl,maxst,idx=1;
        maxpl=0;
        maxst=0;

        for(ll i=1; i<=m; i++)
        {
            ad=b[i];
            sb=c[i];
            pl=mp[ad];
            st=mp[sb];

            if(pl>maxpl)
            {
                maxpl=pl;
                maxst=st;
                idx=i;
            }
            else if(pl==maxpl)
            {
                if(st>maxst)
                {
                    maxpl=pl;
                    maxst=st;
                    idx=i;
                }
            }
        }

        printf("%I64d\n",idx);

    }

    return 0;
}
/*
3
2 3 2
2
3 2
2 3
6
6 3 1 1 3 7
5
1 2 3 4 5
2 3 4 5 1
10
1001 1000000000 1 2 3 1 3 1000000000 1000000000 3
5
1 4 5 9 2
1000000000 1000000000 3 3 1000000000
10
1001 1000000000 1 2 3 1 3 1000000000 1000000000 3
5
10 2 5 9 5
1000000000 9 3 3 1000000000
*/
