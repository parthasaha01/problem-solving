#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int n,f;
double a[10005],v[10005];
bool check(double x)
{
    int cnt=0;

    for(int i=1; i<=n; i++){
        cnt+=(int)(v[i]/x);
    }

    if(cnt<f)return false;
    return true;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d%d",&n,&f);
        f++;

        for(int i=1; i<=n; i++)scanf("%lf",&a[i]);
        for(int i=1; i<=n; i++)v[i] = PI*a[i]*a[i];

        double lo=0.0;
        double hi=1000000005.0;
        double ans;

        for(int i=1; i<=200; i++)
        {
            ans = (lo+hi)/2.0;

            if(check(ans))lo=ans;
            else hi=ans;
        }
        printf("%0.4lf\n",ans);
    }
    return 0;
}
