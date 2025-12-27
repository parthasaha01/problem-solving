#include<bits/stdc++.h>
using namespace std;
double a[1005];
int n,l;
bool check(double r)
{
    double ps=0.0;
    for(int i=1; i<=n; i++){
        if(a[i]-r>ps)return false;
        ps=a[i]+r;
    }
    if(ps<(double)l)return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&l)==2)
    {
        for(int i=1; i<=n; i++){
            scanf("%lf",&a[i]);
        }

        sort(a+1,a+n+1);

        double lo=0.0;
        double hi=(double)l;
        double r;

        for(int k=1; k<=200; k++)
        {
            double md = (lo+hi)/2;

            if(check(md)){
                hi=md;
                r = md;
            }
            else lo=md;
        }
        printf("%.10lf\n",r);
    }
    return 0;
}
