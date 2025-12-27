#include<cstdio>
#include<algorithm>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define sf scanf
#define pf printf
#define ps while(1);
using namespace std;
#include<cmath>
int t;
long long n,s,x,y;
int main(){
    sf("%d",&t);
    re(p,1,t){
        sf("%lld",&s);
        n=ceil(sqrt(double(s)));
        if(n*n-s<n)x=n,y=n*n-s+1;
        else x=-n*n+2*n+s-1,y=n;
        if(n&1)swap(x,y);
        pf("Case %d: %lld %lld\n",p,x,y);
    }
    return 0;
}

