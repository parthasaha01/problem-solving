#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dt{
    ll x,y,d,p;
}st[1005];
ll a[1005],b[1005];
bool cmp(dt p, dt q)
{
    return p.d>q.d;
}
int main()
{
    int n,ka,kb;
    scanf("%d%d%d",&n,&ka,&kb);

    for(int i=1; i<=n; i++){
        scanf("%I64d",&a[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%I64d",&b[i]);
    }

    for(int i=1; i<=n; i++)
    {
        st[i].p = i;
        st[i].x = a[i];
        st[i].y = b[i];
        st[i].d = a[i]-b[i];
        //printf("%lld %lld\n",a[i],b[i]);
        if(st[i].d<0)st[i].d=(-1)*st[i].d;
    }

//    for(int i=1; i<=n; i++){
//        printf("%lld ",st[i].d);
//    }
//    printf("\n");

    sort(st+1,st+n+1,cmp);

//    for(int i=1; i<=n; i++){
//        printf("%lld ",st[i].d);
//    }
//    printf("\n");

    while(ka>0)
    {
        ka--;
        st[1].d--;
        if(st[1].d<0)st[1].d*=(-1);
        sort(st+1,st+n+1,cmp);

//        for(int i=1; i<=n; i++){
//            printf("%lld ",st[i].d);
//        }
//        printf("\n");
    }

    while(kb>0)
    {
        kb--;
        st[1].d--;
        if(st[1].d<0)st[1].d*=(-1);
        sort(st+1,st+n+1,cmp);

//        for(int i=1; i<=n; i++){
//            printf("%lld ",st[i].d);
//        }
//        printf("\n");
    }

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans += (st[i].d*st[i].d);
    }

    printf("%I64d\n",ans);

    return 0;
}
