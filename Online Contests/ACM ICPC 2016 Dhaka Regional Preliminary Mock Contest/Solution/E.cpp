#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    double maxx,minn;
    for(int ks=1; ks<=t; ks++)
    {
        double x;
        scanf("%lf",&x);
        if(ks==1)
        {
            maxx=x;
            minn=x;
        }
        else
        {
            maxx=max(maxx,x);
            minn=min(minn,x);
        }

        double ans=maxx/minn;
        printf("Case %d: %.2lf\n",ks,ans);
    }

    return 0;
}
