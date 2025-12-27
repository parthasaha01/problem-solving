#include<bits/stdc++.h>
using namespace std;
#define mx 100000
struct dt
{
    int a,b,c,d;
}st[mx+5];
struct tt
{
    int v,d;
}sa[mx+5],sb[mx+5],sc[mx+5];
int BinarySearch(int lo,int hi,int v, tt ss[])
{
    int ans=-1;
    while(lo<=hi)
    {
        int md=(lo+hi)/2;
        ans=
        if(ss[md]>v){
            hi=md-1;
        }
        else if(ss[md]<v){
            lo=md+1;
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            int p[5];
            scanf("%d%d%d",&p[0],&p[1],&p[2]);

            sort(p,p+3);

            st[i].a=p[0];
            st[i].b=p[1];
            st[i].c=p[2];
            st[i].d=i;

            sa[i].v=p[0];
            sa[i].d=i;
            sb[i].v=p[1];
            sb[i].d=i;
            sc[i].v=p[2];
            sc[i].d=i;
        }
        int ans1=0;
        int ans2=0;
        int maxx=-1.0;
        int id=0;
        for(int i=1; i<=n; i++)
        {
            int a,b,c,d;
            a=st[i].a;
            b=st[i].b;
            c=st[i].c;
            d=st[i].d;
            double r=(double)a/2.0;

            if(r>maxx){
                maxx=r;
                ans1=d;
            }
        }

        sort(sa,sa+n,cmp);
        sort(sb,sb+n,cmp);
        sort(sc,sc+n,cmp);

        for(int i=1; i<=n; i++)
        {
            int h=st[i].a;

        }

    }

    return 0;
}
