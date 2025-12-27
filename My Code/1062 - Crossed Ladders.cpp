#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        double x,y,c;
        scanf("%lf%lf%lf",&x,&y,&c);

        double lo=0.0;
        double hi=y;    //hi=min(x,y);
        double ans=0.0;
;
        for(int i=0; i<200; i++)
        {
            double w=(lo+hi)/2.0;
            ans=w;
            double hx=sqrt((x*x)-(w*w));
            double hy=sqrt((y*y)-(w*w));
            double cc=(hx*hy)/(hx+hy);  //Cross Ladder Theorem

            if(cc>c) lo=w;
            if(cc<c) hi=w;
        }
        printf("Case %d: %.10lf\n",ks,ans);
    }

    return 0;
}
