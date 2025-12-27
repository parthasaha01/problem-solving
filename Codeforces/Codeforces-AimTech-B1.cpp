#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
ll x[mx];
int main()
{
    ll n,a;

    while(scanf("%I64d%I64d",&n,&a)==2)
    {
        for(ll i=0; i<n; i++)
        {
            scanf("%I64d",&x[i]);
        }

        sort(x,x+n);

        ll cost=0;

        if(n==1)
        {
            cost=0;
        }
        else if(n==2)
        {
            ll cost1=abs(a-x[0]);
            ll cost2=abs(a-x[1]);
            cost = min(cost1,cost2);
        }
        else if(a>=x[0] && a<=x[n-1])
        {

            if(a==x[0])
            {
                cost=abs(a-x[n-2]);
            }
            else if(a==x[n-1])
            {
                cost=abs(a-x[1]);
            }
            else
            {
                //cout << "partha" << endl;
                ll cost1,cost2;
                ll diff1,diff2;

                diff1=abs(a-x[1]);
                diff2=abs(a-x[n-1]);

                if(diff1<=diff2)
                {
                    cost1 = abs(a-x[1])+abs(x[1]-x[n-1]);
                }
                else
                {
                    cost1=abs(a-x[n-1])+abs(x[n-1]-x[1]);
                }

                diff1=abs(a-x[0]);
                diff2=abs(a-x[n-2]);

                if(diff1<=diff2)
                {
                    cost2=abs(a-x[0])+abs(x[0]-x[n-2]);
                }
                else
                {
                    cost2=abs(a-x[n-2])+abs(x[n-2]-x[0]);
                }

                cost = min(cost1,cost2);
            }
        }
        else if(a<x[0])
        {
            cost=abs(a-x[n-2]);
        }
        else if(a>x[n-1])
        {
            cost=abs(a-x[1]);
        }

        printf("%I64d\n",cost);
    }

    return 0;
}
/*

*/

