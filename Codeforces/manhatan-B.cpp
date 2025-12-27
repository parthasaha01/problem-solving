#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx+5];
int main()
{
    ll n,p,q,r;
    scanf("%I64d %I64d %I64d %I64d",&n,&p,&q,&r);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
    }

    ll x,y,z;
    ll xi,yj,zk;

    x=1,y=1,z=1;
    xi=p*a[1]; yj=q*a[1]; zk=r*a[1];

    ll maxx = xi+yj+zk;

    for(int i=2; i<=n; i++)
    {
//        ll temp = p*a[i]+q*a[i]+r*a[i];
//        maxx = max(maxx,temp);
        ll txi,tyj,tzk;
        ll temp;

        tzk = r*a[i];
        temp = xi+yj+tzk;
        maxx = max(maxx,temp);

        tyj = q*a[i];
        temp = xi+tyj+tzk;
        maxx = max(maxx,temp);

        txi = p*a[i];
        temp = txi+tyj+tzk;
        maxx = max(maxx,temp);

        if(tzk>zk){
            zk = tzk;
            z=i;
            temp = xi+yj+zk;
            maxx = max(maxx,temp);
        }
        if(tyj>yj){
            yj=tyj;
            zk=tzk;
            x=i; y=i;
            temp = xi+yj+zk;
            maxx = max(maxx,temp);
        }
        if(txi>xi)
        {
            if(((p*txi)+(q*tyj))>(xi+yj))
            {
                xi=txi;
                yj=tyj;
                zk=tzk;
                x=i; y=i; z=i;
                temp = xi+yj+zk;
                maxx = max(maxx,temp);
            }
        }

        temp = xi+yj+zk;
        maxx = max(maxx,temp);
    }

    printf("%I64d\n",maxx);

    return 0;
}
