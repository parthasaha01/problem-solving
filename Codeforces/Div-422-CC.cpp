#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 200005
//ll fr[mx+5][2],sc[mx+5][2];
ll n,x;
vector<ll>vv[mx+5];
struct dt
{
    ll li,ri,ci,di;
}st[mx+5];
int main()
{
    scanf("%I64d %I64d",&n,&x);

    for(ll i=1; i<=n; i++)
    {
        ll l,r,c,d;
        scanf("%I64d %I64d %I64d",&l,&r,&c);
        d = r-l+1;
        st[i].li = l;
        st[i].ri = r;
        st[i].ci = c;
        st[i].di = d;
    }

    for(ll i=1; i<=n; i++)
    {
        ll l,r,c,d;
        l = st[i].li;
        r = st[i].ri;
        c = st[i].ci;
        d = st[i].di;

        if(x>d)
        {
            ll p = x-d;
            vv[p].push_back(i);
        }
    }

//    for(ll i=1; i<=x; i++)
//    {
//        printf("i=%lld : ",i);
//        for(int k=0; k<vv[i].size(); k++)
//        {
//            printf("%lld ",vv[i][k]);
//        }
//        printf("\n");
//    }

    ll ans = 1000000000000;

    for(ll i=1; i<=n; i++)
    {
        ll lx,rx,cx,dx;
        lx = st[i].li;
        rx = st[i].ri;
        cx = st[i].ci;
        dx = st[i].di;


        //if(x<=dx)continue;

        //ll p = x-dx;

        //printf("i=%lld dx=%lld p=%lld\n",i,dx,p);

        for(ll k=0; k<vv[dx].size(); k++)
        {
            ll j = vv[dx][k];

            if(i==j)continue;

            ll ly,ry,cy,dy;
            ly = st[j].li;
            ry = st[j].ri;
            cy = st[j].ci;
            dy = st[j].di;

            //cout << "abir"<< endl;

            //printf("i=%I64d dx=%I64d j=%I64d dy=%I64d\n",i,dx,j,dy);

            if(x==dx+dy)
            {
                //cout << "partha"<< endl;
                if( (rx<ly) || (ry<lx))
                {
                    //cout << "tonmoy" << endl;
                    ll cnt = cx+cy;
                    ans = min(ans,cnt);
                }
            }
        }
    }

    if(ans<1000000000000)printf("%I64d\n",ans);
    else{
        printf("-1\n");
    }

    return 0;
}

