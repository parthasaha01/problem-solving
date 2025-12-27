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
    FOR(i,0,200)
    {
        mid=(lo+hi)/2.0;
        //cout<<mid<<endl;
        lit_r=(big_r-mid);
        d=2*mid;
        perimeter=2.0*PI*(big_r-mid);
        theta=acos(((2.0*(lit_r*lit_r))-(d*d))/(2.0*lit_r*lit_r));
        val=theta*lit_r*n;
        if(val>perimeter){
            //printf("l i=%d lo=%f hi=%f mid=%f perimeter=%f val=%f\n",i,lo,hi,mid,perimeter,val);
            hi=mid;
        }
        else{
            //printf("l i=%d lo=%f hi=%f mid=%f perimeter=%f val=%f\n",i,lo,hi,mid,perimeter,val);
            lo=mid;
        }
    }

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
