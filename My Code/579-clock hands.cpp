#include<bits/stdc++.h>
using namespace std;
int main()
{
    int H,M;
    double H1,M1,T,angle,diff;
    char ch;

    while(scanf("%d",&H)==1)
    {
        scanf("%c",&ch);
        scanf("%d",&M);

        if(H==0.0 && M==0.0)
        {
            break;
        }

        //M1=M/5;
        H1=H*5.0;
        diff=H1-M;
        diff += (M/12.0);
        angle=abs(diff*6.0);

        if(angle>180.0)
        {
            angle=360.0-angle;
        }

        printf("%.3lf\n",angle);
    }

    return 0;
}
