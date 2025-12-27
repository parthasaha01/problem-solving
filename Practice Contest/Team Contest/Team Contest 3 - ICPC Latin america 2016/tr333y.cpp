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
double arr[mx],cc[mx];
point p[mx];
int main()
{

    while(scanf("%d",&n)==1)
    {
        double inc = 360.0/n;
        double angle = 90.0;
        double maxx = 0.0;
        //angle = angle*(PI/180.0);

        //cout << cos(angle) << endl;
        for(int i=0; i<n; i++)
        {
            scanf("%lf",&arr[i]);
        }
        sort(arr,arr+n);
        while(next_permutation(arr,arr+n))
        {

//            for(int i=0; i<n; i++)
//            {
//                cout<<arr[i]<<" ";
//            }
//            cout<<endl;
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
            //cout<<area<<endl;
            //maxx = max(maxx,area);
            if(area>maxx){
                maxx = area;
                if(area>=2772.00)
                {
                    cout << area << " ";
                     for(int i=0; i<n; i++)
                        cout<<arr[i]<<" ";
                    cout<<endl;
                }
                for(int u=0; u<n; u++){
                    cc[u] = arr[u];
                }
            }

        }

        cout << maxx << endl;
        for(int i=0; i<n; i++)
        {
                cout<<cc[i]<<" ";
        }
        cout << endl;
    }
    return 0;
}


