#include<bits/stdc++.h>
using namespace std;
#define mx 100000007
double a[100005],ca[100005];
void precalc()
{
    for(int i=1; i<=100001; i++){
        double sum=0.0;
        double n=(i-1)*1000+1;
        for(int j=1; j<=1000; j++,n+=1.0){
            sum+=(1.0/n);
        }
        a[i]=sum;
    }
    ca[0]=0.0;
    for(int i=1; i<=100001; i++){
        ca[i]=ca[i-1]+a[i];
    }
}
double calculate(int n)
{
    int d=n/1000;
    double sum=ca[d];
    int r=n%1000;
    double x=d*1000+1;
    for(int i=1; i<=r; i++,x+=1.0){
        sum+=(1.0/x);
    }

    return sum;
}
int main()
{
    precalc();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);
        double ans=calculate(n);
        printf("Case %d: %.10lf\n",ks,ans);
    }

    return 0;
}
