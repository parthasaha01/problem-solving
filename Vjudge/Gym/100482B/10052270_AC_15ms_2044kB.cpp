#include<bits/stdc++.h>
using namespace std;
#define LD double
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        LD x1,y1,x2,y2,x3,y3,x4,y4,cost;
        scanf("%lf %lf",&x1,&y1);
        scanf("%lf %lf",&x2,&y2);
        scanf("%lf %lf",&x3,&y3);
        scanf("%lf %lf",&x4,&y4);
        scanf("%lf",&cost);

//        printf("%lf %lf\n",x1,y1);
//        printf("%lf %lf\n",x2,y2);
//        printf("%lf %lf\n",x3,y3);
//        printf("%lf %lf\n",x4,y4);
//        printf("%lf\n",&cost);


        LD pp = (x1*y2) + (x2*y3) + (x3*y4) + (x4*y1);
        LD qq = (x2*y1) + (x3*y2) + (x4*y3) + (x1*y4);

        LD rr = pp-qq;
        LD ss = 0.5*rr;
        if(ss<0.0){
            ss = (-1.0)*ss;
        }

        LD ans = cost/ss;

        printf("Case #%d: %0.2lf\n",ks,ans);
    }
    return 0;
}
