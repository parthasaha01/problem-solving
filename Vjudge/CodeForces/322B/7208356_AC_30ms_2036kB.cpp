#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b;

    while(scanf("%d%d%d",&r,&g,&b)==3)
    {
        int ans1=0;
        //int minn=1000000009;

        int minn=min(r,min(g,b));

        ans1+=minn;
        int r1=r-minn;
        int g1=g-minn;
        int b1=b-minn;

        ans1+=(r1/3)+(g1/3)+(b1/3);

        int ans2=0;

        if(minn!=0)
        {
            minn=minn-1;
            ans2+=minn;
            int r2=r-minn;
            int g2=g-minn;
            int b2=b-minn;

            ans2+=(r2/3)+(g2/3)+(b2/3);
        }


        int ans=max(ans1,ans2);

        printf("%d\n",ans);

    }

    return 0;
}

