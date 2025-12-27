#include<bits/stdc++.h>
using namespace std;
int a[105];
struct dt
{
    int l,r,d,m;
}st[20005];
bool cmp(dt x,dt y)
{
    if(x.d==y.d){
        return x.l<y.l;
    }
    else{
        return x.d<y.d;
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n,q;
        scanf("%d%d",&n,&q);

        for(int i=0; i<q; i++)
        {
            int l,r,m;
            scanf("%d%d%d",&l,&r,&m);
            st[i].l=l;
            st[i].r=r;
            st[i].d=(r-l);
            st[i].m=m;
        }

        sort(st,st+q,cmp);
        memset(a,-1,sizeof(a));

        for(int i=0; i<q; i++)
        {
            int l=st[i].l;
            int r=st[i].r;
            int m=st[i].m;

            for(int x=l; x<=r; x++)
            {
                a[x]=max(m,a[x]);
            }
        }

        for(int x=1; x<=n; x++)
        {
            if(a[x]==-1)
            {
                a[x]=20000;
            }
        }

        printf("Case %d:",ks);
        for(int i=1; i<=n; i++){
            printf(" %d",a[i]);
        }
        printf("\n");
    }

    return 0;
}
/*
10

7 5
1 4 4
4 7 12
2 2 17
1 7 4
4 5 32

7 7
1 3 2
1 2 2
2 5 2
3 6 2
4 7 4
5 6 5
1 7 2


10 5
2 4 1
5 9 6
1 10 1
1 3 2
2 7 1



*/
