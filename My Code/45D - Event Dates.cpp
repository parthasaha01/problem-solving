#include<bits/stdc++.h>
using namespace std;
struct dt{
    int l,r,i;
}st[105];
int ans[105];
int vis[10000005];
bool cmp1(dt x, dt y)
{
    if(x.r!=y.r) return x.r<y.r;
    return x.l>y.l;
}
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++){
        int l,r; scanf("%d %d",&l,&r);
        st[i].l = l;
        st[i].r = r;
        st[i].i = i;
    }

    sort(st+1,st+n+1,cmp1);

    for(int i=1; i<=n; i++)
    {
        int l = st[i].l;
        int r = st[i].r;
        int id = st[i].i;

        //int f = 0;
        for(int j=l; j<=r; j++){
            if(vis[j]==0){
                ans[id] = j;
                vis[j] =1;
               // f = 1;
                break;
            }
        }

//        if(f==0){
//            while(1)
//            {
//                //
//            }
//        }
    }

    for(int i=1; i<=n; i++){
        if(i<n)printf("%d ",ans[i]);
        else printf("%d\n",ans[i]);
    }

    return 0;
}
