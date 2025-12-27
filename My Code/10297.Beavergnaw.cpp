#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)

int main()
{
    double D,V,d,total,part,res,ans;

    while(scanf("%lf%lf",&D,&V))
    {
        if(D==0.0 && V==0.0){
            break;
        }

        res = (D*D*D)-((6*V)/PI);
        //printf("res = %lf\n",res);
        ans = pow(res,(1/3.0));

        printf("%.3lf\n",ans);

    }

    return 0;
}
