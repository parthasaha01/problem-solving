#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        double n = a+b;
        double ans = ((b/n)*((b-1.0)/(n-c-1.0))) + ((a/n)*(b/(n-c-1.0)));
        printf("%.5f\n",ans);
    }
    return 0;
}
