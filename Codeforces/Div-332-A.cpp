#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int d1,d2,d3,res,val;

    while(scanf("%ld %ld %ld",&d1,&d2,&d3)==3)
    {
        res=1000000000;
        val=d1+d2+d3;
        res=min(res,val);
        val=2*(d1+d2);
        res=min(res,val);
        val=2*(d1+d3);
        res=min(res,val);
        val=2*(d2+d3);
        res=min(res,val);
        val=(3*d1)+d2+d3;
        res=min(res,val);
        val=d1+(3*d2)+d3;
        res=min(res,val);
        printf("%ld\n",res);
    }

    return 0;
}
