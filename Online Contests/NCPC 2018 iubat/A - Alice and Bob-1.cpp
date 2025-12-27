#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100000
struct dt{
    int x,i;
}qr[30005];
struct pq{
    int x,i;
}bb[30005];
int n,q,a[30005],st[30005][16];
ll res[30005];
set< pair<int,int> >ss;
//map<int,int>mp;
bool cmp1(pq s,pq t){
    if(s.x==t.x)return s.i<t.i;
    return s.x<t.x;
}
bool cmp2(dt s,dt t){
    if(s.x==t.x)return s.i<t.i;
    return s.x<t.x;
}
void sparsetable()
{
    for(int i=1; i<=n; i++)st[i][0]=i;

    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            int x,y;
            x = st[i][j-1];
            y = st[i+(1<<(j-1))][j-1];
            if(a[x]<=a[y])st[i][j] = x;
            else st[i][j] = y;
        }
    }
}
ll query(int b,int e)
{
    int x,y,k;
    k = (int)log2(e-b+1);
    x = st[b][k];
    y = st[e-(1<<k)+1][k];
    ll minn = min(a[x],a[y]);
    return minn;
}
int Search(int x)
{
    int pos = 0;
    int lo=1,hi=n;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(bb[md].x<=x){
            pos=md;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }
    return pos;
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        ss.clear();

        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            bb[i].x = a[i];
            bb[i].i = i;
        }

        sparsetable();

        for(int i=1; i<=q; i++){
            scanf("%d",&qr[i].x);
            qr[i].i = i;
        }

        sort(bb+1,bb+n+1,cmp1);
        sort(qr+1,qr+q+1,cmp2);

        ss.insert(1,n);
        ss.insert(n+5,n+5);

        ll ans = (ll)query(1,n)*(ll)n;
        int cur = 0;

        for(int k=1; k<=q; k++)
        {
            int x = qr[k].x;
            int idx = qr[k].i;
            int p = Search(x);

            if(p<=cur){
                res[qr[k].i]=ans;
                continue;
            }

            for(int j=cur+1;j<=p; j++)
            {
                int v = bb[j].x;
                int id = bb[j].i;

                //auto it = lower_bound(ss.begin(),ss.end(),make_pair(id,-100000));

                auto it = ss.lower_bound(make_pair(id,-inf));

                int l=0,r=0;
                //l = (*it).first;
                //r = (*it).second;

               // if((*it).first>id)it--;

                ss.erase(it);

                ll minn = query(l,r);
                ans -= minn*(r-l+1LL);

                int la = l;
                int ra = id-1;
                int lb = id+1;
                int rb = r;

                if(la<=ra){
                    minn = query(la,ra);
                    ans += minn*(ra-la+1LL);
                    ss.insert(make_pair(la,ra));
                }

                if(lb<=rb){
                    minn = query(lb,rb);
                    ans += minn*(rb-lb+1LL);
                    ss.insert(make_pair(lb,rb));
                }
            }

            cur = p;
            res[idx] = ans;
        }

        for(int i=1; i<=q; i++){
            printf("%lld\n",res[i]);
        }
    }
    return 0;
}

/*

1
8 6
9 10 6 8 10 5 12 13
9
8
7
4
5
10

*/

