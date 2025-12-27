#include<bits/stdc++.h>
using namespace std;
int a[100005],n,q;
int UpperBound(int v)
{
    int lo  = 1;
    int hi  = n;
    int ans = 0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(a[md]<=v){
            ans=md;
            lo=md+1;
        }
        else hi=md-1;
    }
    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);
        scanf("%d%d",&n,&q);

        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        for(int k=1; k<=q; k++)
        {
            int lb,hb; scanf("%d%d",&lb,&hb);
            int ans = UpperBound(hb)-UpperBound(lb-1);
            printf("%d\n",ans);
        }
    }

    return 0;
}

