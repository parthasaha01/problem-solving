#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,n,res;

    while(scanf("%lld %lld %lld",&a,&b,&n))
    {
        if(a==0&&b==0&&n==0)
            return 0;
        n%=5;
        if(n==0){
            printf("%lld\n",a);
        }
        else if(n==1){
            printf("%lld\n",b);
        }
        else if(n==2){
            res=(b+1)/a;
            printf("%lld\n",res);
        }
        else if(n==3){
            res=(a+b+1)/(a*b);
            printf("%lld\n",res);
        }
        else{
            res=(a+1)/b;
            printf("%lld\n",res);
        }
    }
}

