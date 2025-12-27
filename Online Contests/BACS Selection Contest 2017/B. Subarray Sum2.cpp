#include<bits/stdc++.h>
using namespace std;
#define mx 5002
int n,k,a[mx];
//int fun(int p,int x)
//{
//    if(x<0)return -1000000000;
//    if(p==0){ return 0; }
//
//    if(dp[p][x]!=-1)return dp[p][x];
//
//    int ret=0;
//
//    if(a[p]>=0)
//    {
//        ret = max(0,a[p]+fun(p-1,x));
//    }
//    else
//    {
//        int ret1=-1000000000,ret2=-1000000000, ret3=-1000000000;
//
//        ret1 = max(0,a[p]+fun(p-1,x));
//        ret2 = max(0,fun(p-1,x-1));
//        ret3 = fun(p-1,x);
//        ret = max(ret1,max(ret2,ret3));
//    }
//
//    dp[p][x]=ret;
//    return dp[p][x];
//}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&k);

        int ng=0;
        int mxx = -1000000000;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<0)ng++;
            mxx = max(a[i],mxx);
        }

        if(ng==n)
        {
            if(k==0)printf("Case %d: %d\n",ks,mxx);
            else printf("Case %d: 0\n",ks);
            continue;
        }

        if(ng<=k)
        {
            int sum=0;

            for(int i=1; i<=n; i++)
            {
                if(a[i]>0)sum+=a[i];
            }

            printf("Case %d: %d\n",ks,sum);
            continue;
        }

        int ans = mxx;
        for(int i=n; i>=1; i--)
        {
            int cnt=0;
            int minn=0;
            int x=0;
            priority_queue<int>pq;

            for(int j=i; j>=1; j--)
            {
                if(a[j]<0)
                {
                    x++;
                    pq.push(a[j]);
                    //minn = min(minn,a[i]);
                    if(x>k)
                    {
                        int v = pq.top();
                        pq.pop();
                        cnt += v;
                        x--;
                    }
                }
                else
                {
                    cnt += a[j];
                }

                ans = max(ans,cnt);
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}

/*
5 1
-100 2 -100 105 -200
*/
