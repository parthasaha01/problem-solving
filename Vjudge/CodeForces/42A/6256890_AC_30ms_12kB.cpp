#include<bits/stdc++.h>
using namespace std;
struct type{
    double a,b,c,d;
}m[25];

int main()
{
    int n;
    double res,v;

    while(scanf("%d%lf",&n,&v)==2)
    {
        double suma=0.0;
        for(int i=0; i<n; i++){
            scanf("%lf",&m[i].a);
            suma += m[i].a;
        }
        double sumb=0.0;
        for(int i=0; i<n; i++){
            scanf("%lf",&m[i].b);
            sumb += m[i].b;
        }

        /*for(int i=0; i<n; i++){
            m[i].c = (v*m[i].a)/suma;
        }*/

        double low=0.0;
        double high;
        if(v<sumb){
            high=v;
        }
        else{
            high=sumb;
        }

        for(int k=0; k<=200; k++)
        {

            double mid = (low+high)/2.0;
            double x=mid;
            res=x;

            int flag=1;


            for(int i=0; i<n; i++){
                double p = (x*m[i].a)/suma;
                if(p>m[i].b){
                    flag=0;
                    break;
                }
            }

            //printf("low=%lf high=%lf mid=%lf flag=%d\n",low,high,mid,flag);

            if(flag){
                low=mid;
            }
            else{
                high=mid;
            }
        }

        printf("%lf\n",res);


    }

    return 0;
}
