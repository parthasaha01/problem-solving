#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll ax1,ax2,ay1,ay2;
        ll bx1,bx2,by1,by2;
        ll px1,px2,py1,py2;

        scanf("%lld%lld%lld%lld",&ax1,&ay1,&ax2,&ay2);
        scanf("%lld%lld%lld%lld",&bx1,&by1,&bx2,&by2);

//        if((ax1==bx1)&&(ay1==by1)&&(ax2==bx2)&&(ay2==by2)){
//            printf("no\n"); continue;
//        }
//
//        if((ax2==bx1)&&(ay2==by1)&&(ax1==bx2)&&(ay1==by2)){
//            printf("no\n"); continue;
//        }

        if((ax1==ax2)&&(ax2==bx1)&&(bx1==bx2))
        {
            py1 = min(ay1,ay2);
            py2 = max(ay1,ay2);

            if((by1>=py1 && by1<=py2) || (by2>=py1 && by2<=py2)){
                printf("yes\n"); continue;
            }

            py1 = min(by1,by2);
            py2 = max(by1,by2);

            if((ay1>=py1 && ay1<=py2) || (ay2>=py1 && ay2<=py2)){
                printf("yes\n"); continue;
            }

            printf("no\n"); continue;
        }

        if((ay1==ay2)&&(ay2==by1)&&(by1==by2))
        {
            px1 = min(ax1,ax2);
            px2 = max(ax1,ax2);

            if((bx1>=px1 && bx1<=px2) || (bx2>=px1 && bx2<=px2)){
                printf("yes\n"); continue;
            }

            px1 = min(bx1,bx2);
            px2 = max(bx1,bx2);

            if((ax1>=px1 && ax1<=px2) || (ax2>=px1 && ax2<=px2)){
                printf("yes\n"); continue;
            }

            printf("no\n"); continue;
        }

        if(ax1==bx1 && ay1==by1){ printf("yes\n"); continue; }
        if(ax1==bx2 && ay1==by2){ printf("yes\n"); continue; }
        if(ax2==bx1 && ay2==by1){ printf("yes\n"); continue; }
        if(ax2==bx2 && ay2==by2){ printf("yes\n"); continue; }

        printf("no\n");
    }

    return 0;
}
