#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m;
bool check(int v)
{
    int k=1;
    int tm = 0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>v)return false;

        if(tm+a[i]<=v){
            tm+=a[i];
        }
        else{
            k++;
            tm=a[i];
        }

        if(k>m)return false;
    }

    return true;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        int lo=0;
        int hi=1000000005;
        int ans;

        while(lo<=hi)
        {
            int md = lo + (hi-lo)/2;
            if(check(md)==true){
                ans = md;
                hi=md-1;
            }
            else lo = md+1;
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
