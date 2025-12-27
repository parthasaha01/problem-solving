#include<bits/stdc++.h>
using namespace std;
#define mx 100010
#define PI acos(-1)
struct point
{
    double x;
    double y;
};
int n;
double brr[mx],cc[mx];
vector<double>arr;
point p[mx];
int main()
{

    while(scanf("%d",&n)==1)
    {
        arr.clear();
        double inc = 360.0/n;
        double angle = 90.0;
        double maxx = 0.0;
        //angle = angle*(PI/180.0);

        //cout << cos(angle) << endl;
        for(int i=0; i<n; i++)
        {
            scanf("%lf",&brr[i]);
        }
        sort(brr,brr+n);
        arr.push_back(brr[0]);
        arr.push_back(brr[1]);
        int ii;
        for(ii=3;ii<n;ii++)
        {
            if(ii%2)
            arr.push_back(brr[ii]);
        }
        for(int i=n-1;i>=2;i--)
        {
            if(i%2==0)
            arr.push_back(brr[i]);
        }
//        for(int i=0;i<arr.size();i++)
//            cout<<arr[i]<<" ";
        for(int i=0; i<n; i++)
        {
            double theta = angle*(PI/180.0);
            p[i].x= (double)arr[i]*(double)cos(theta);
            p[i].y= (double)arr[i]*(double)sin(theta);
            if(fabs(p[i].x)<.000000001)
                p[i].x=0;
            if(fabs(p[i].y)<.000000001)
                p[i].y=0;
            angle -= inc;
            //cout<<p[i].x<<" "<<p[i].y<<endl;
        }
        double sum1=0,sum2=0;
        for(int i =0 ; i<n-1; i++)
        {
            sum1+=p[i].x * p[i+1].y;
            sum2+=p[i].y * p[i+1].x;
        }
        sum1+=p[n-1].x * p[0].y;
        sum2+=p[n-1].y * p[0].x;

        double sum = fabs(sum1-sum2);
        double area = 0.5*sum;
        printf("%.3lf\n",area);
        //cout<<area<<endl;
    }
//
//    cout << maxx << endl;
//    for(int i=0; i<n; i++)
//    {
//        cout<<cc[i]<<" ";
//    }
//    cout << endl;
//}
return 0;
}



