#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
int main()
{
    double D,V,d,total,part,res,ans;

    //printf("%lf\n",PI);

    while(cin >> D >> V)
    {
        if(D==0.0 && V==0.0){
            break;
        }

        double low,high;
        low=0.0;
        high=D;

        //total = (PI*power(D,3.0))/4.0;
        total = (PI*D*D*D)/4.0;

        while(low<high)
        {
            printf("partha\n");
            double mid = (low+high)/2.0;
            d=mid;

            part = (PI*d*d*d)/4.0;
            res = part + 2*V;

            printf("low=%Lf high=%Lf mid=%Lf\n",low,high,mid);
            printf("total=%Lf part=%Lf res=%Lf\n\n",total,part,res);

            if(abs(total-res)<=0.000001){
                ans=mid;
                break;
            }

            if(res<total){
                low=mid;
            }
            else{
                high=mid;
            }
        }

        printf("%.3Lf\n",ans);

    }

    return 0;
}

