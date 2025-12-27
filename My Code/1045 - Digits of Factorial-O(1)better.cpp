#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)   //#define pi 2.0*acos(0.0)
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        int n,b;
        scanf("%d %d",&n,&b);//stirling formula
        double ans;

        if(n==0){
            ans=1;
        }
        else{
            ans=n*log(n)-n+0.5*log(2*pi*n);
            ans/=log(b);
            ans++;
        }

        printf("Case %d: %d\n",ks,(int)floor(ans));
    }
    return 0;
}
