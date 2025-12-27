#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
#define ll long long int
ll r[mx],c[mx],x[mx],y[mx];
int main()
{
    ll n,m;

    scanf("%I64d%I64d",&n,&m);


    for(int i=1; i<=m; i++)
    {
        scanf("%I64d%I64d",&x[i],&y[i]);
    }
    ll sum = n*n;
    ll cntr,cntc;
    cntr=cntc=n;
    for(int i=1; i<=m; i++)
    {
        ll a=x[i];
        ll b=y[i];

        if(sum>0)
        {
            if(r[a]==0)
            {
                sum = sum-cntc;
                cntr--;
                r[a]=1;
            }
            if(c[b]==0)
            {
                sum = sum-cntr;
                cntc--;
                c[b]=1;
            }
        }

        if(sum<0)
            sum = 0;

        if(i<m)
            printf("%I64d ",sum);
        else
            printf("%I64d\n",sum);
    }

    return 0;

}

