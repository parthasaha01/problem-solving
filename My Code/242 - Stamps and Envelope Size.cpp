#include<bits/stdc++.h>
using namespace std;
int n,sz,b[15];
bool flag[1005],dp[12][12][1005];
struct dt
{
    int sz;
    int a[15];
}st[15];
void fun(int p,int k,int s)
{
    flag[s]=true;
    if(p>sz)return;

    if(dp[p][k][s]==true)return;

    for(int i=1; i<=n; i++)
    {
        if(k-i>=0)fun(p+1,k-i,s+b[p]*i);
    }
    fun(p+1,k,s);

    dp[p][k][s]=true;
    return;
}
bool cmp(dt x, dt y)
{
    if(x.sz==y.sz){
        for(int i=x.sz; i>=1; i--){
            if(x.a[i]!=y.a[i]){
                return x.a[i] < y.a[i];
            }
        }
    }

    return x.sz<y.sz;
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        int q; scanf("%d",&q);

        for(int i=1; i<=q; i++)
        {
            int zz; scanf("%d",&zz);
            st[i].sz=zz;
            for(int j=1; j<=zz; j++)
            {
                int v; scanf("%d",&v);
                st[i].a[j] = v;
            }
        }

        sort(st+1, st+q+1,cmp);

//        for(int i=1; i<=q; i++){
//            for(int j=1; j<=st[i].sz; j++){
//                printf("%d ",st[i].a[j]);
//            }
//            printf("\n");
//        }

        int ans=0,id=1;

        for(int i=1; i<=q; i++)
        {
            sz = st[i].sz;
            for(int j=1; j<=sz; j++)
                b[j] = st[i].a[j];

            memset(dp,false,sizeof(dp));
            memset(flag,false,sizeof(flag));

            fun(1,n,0);

            int cnt=0;
            for(int k=1; k<=1000; k++)
            {
                if(flag[k])cnt++;
                else break;

                if(cnt>ans){
                    ans = cnt;
                    id = i;
                }
            }
        }

        printf("max coverage =%4d :",ans);
        for(int i=1; i<=st[id].sz; i++){
            printf("%3d",st[id].a[i]);
        }
        printf("\n");

    }
    return 0;
}
