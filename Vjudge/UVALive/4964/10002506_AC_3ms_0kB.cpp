#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a1,a2,a3,a4;

    while(cin>>a1>>a2>>a3)
    {
        if(a1==0&&a2==0&&a3==0)break;

        ll r1 = a2-a1;
        ll r2 = a3-a2;

        if(r1==r2){
            printf("AP %lld\n",a3+r1);
        }
        else{
            r1 = a2/a1;
            printf("GP %lld\n",a3*r1);
        }
    }
    return 0;
}
