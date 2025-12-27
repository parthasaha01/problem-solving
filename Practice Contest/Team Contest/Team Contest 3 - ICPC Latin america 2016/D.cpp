#include<bits/stdc++.h>
using namespace std;
#define mx 100010

struct point
{
    double x;
    double y;
};
int n;
double arr[mx];
point p[mx];
int main()
{

    while(scanf("%d",&n)==1)
    {
        double angle = 360.0/n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);

            p[i].x= (double)arr[i]*(double)cos((i+1)*angle);
            p[i].y= (double)arr[i]*(double)sin((i+1)*angle);
            cout<<p[i].x<<" "<<p[i].y<<endl;
        }
//        for(int i=0;i<n;i++)
//        {
//            cin>>p[i].x>>p[i].y;
//        }

        double sum1=0,sum2=0;
        for(int i =0 ;i<n-1;i++)
        {
            sum1+=p[i].x * p[i+1].y;
            sum2+=p[i].y * p[i+1].x;
        }
        sum1+=p[n-1].x * p[0].y;
        sum2+=p[n-1].y * p[0].x;


        cout<<.5*(sum1 -sum2)<<endl;

        //cout<<angle<<endl;



    }

    return 0;
}
