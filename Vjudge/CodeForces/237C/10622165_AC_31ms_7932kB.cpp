#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000000
int flag[mx+5],sum[mx+5];
vector<int>pr;
int a,b,k;
void sieve()
{
    flag[0]=flag[1]=1;
    for(int i=4; i<=mx; i+=2)flag[i]=1;
    //pr.push_back(2);

    for(ll i=3; i<=mx; i+=2)
    {
        if(flag[i]==0)
        {
            //pr.push_back(i);
            for(ll j=i*i; j<=mx; j+=i+i){
                flag[j]=1;
            }
        }
    }

    sum[0]=0;
    for(int i=1; i<=mx; i++)
    {
        if(flag[i]==0)sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
    }
}
bool check(int x)
{
    for(int i=a; i+x-1<=b; i++)
    {
        int ii = i+x-1;
        //cout << x << " " << i << " " << ii << " " << sum[ii]-sum[i-1] << endl;
        if(sum[ii]-sum[i-1]<k){
            return false;
        }
    }

    return true;
}
int main()
{
    sieve();

    scanf("%d%d%d",&a,&b,&k);

    if(a>b)swap(a,b);

    int ans=-1;

    int lo=1;
    int hi=b-a+1;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        //cout << "md=" << md << endl;

        if(check(md)==true){
            ans=md;
            hi=md-1;
        }
        else{
            lo = md+1;
        }
    }

    printf("%d\n",ans);

    return 0;
}
