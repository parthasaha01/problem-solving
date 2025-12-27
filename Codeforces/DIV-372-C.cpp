#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long
#define mx 10000
vector<llu>v;
llu calculation(llu x,llu clv, llu nlv)
{
    llu nm=nlv;
    bool flag=true;
    llu res=0;

    while(flag)
    {
        llu sq=nm*nm;
        llu need=abs(sq-x);

        if(need%clv==0){
            res=need/clv;
            flag=false;
            break;
        }
        nm+=nlv;
    }

    return res;
}
void precalculation()
{
    llu x=2;

    for(int i=1; i<=mx; i++)
    {
        llu res=calculation(x,i,i+1);
        v.push_back(res);
        x=sqrt(x+res*i);
    }
}
int main()
{
    precalculation();

    llu n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++){
            printf("%llu\n",v[i]);
        }
    }

    return 0;
}
