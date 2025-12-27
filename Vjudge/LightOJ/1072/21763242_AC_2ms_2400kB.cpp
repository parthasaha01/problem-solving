#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
//#define PI acos(0.0)
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
int test,cas=0,n;
double big_r,lit_r;
void binary_fun()
{
    double lo=0.00,hi=big_r/2.0,mid,val,perimeter,theta,d;
    // The maximum possible value of r  can be (R/2) if n>=2
    FOR(i,0,200)
    {
        mid=(lo+hi)/2.0;
        //cout<<mid<<endl;
        lit_r=(big_r-mid);
        d=2*mid;
        perimeter=2.0*PI*(big_r-mid);
        double x = (2.0*(lit_r*lit_r))-(d*d);
        double y = 2.0*lit_r*lit_r;
        double xy = x/y;
        // the value of xy must be among [-1, +1].
        // Because the value of cos@ will be always in range [-1, +1]
        // here, if the value of mid is greater than (big_r/2.0) then
        // the value of xy will be always less than -1
        theta=acos(xy);
        val=theta*lit_r*n;
        if(val>perimeter){
            //printf("h i=%d lo=%f hi=%f mid=%f x=%f y=%f xy=%f perimeter=%f val=%f\n",i,lo,hi,mid,x,y,xy,perimeter,val);
            hi=mid;
        }
        else{
            //printf("l i=%d lo=%f hi=%f mid=%f x=%f y=%f xy=%f perimeter=%f val=%f\n",i,lo,hi,mid,x,y,xy,perimeter,val);
            lo=mid;
        }
    }

    // Try to use %f for print double value if %lf print unexpected value
    printf("Case %d: %.10f\n",++cas,mid);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>test;
    while(test--)
    {
        cin>>big_r>>n;
        binary_fun();
    }
}
