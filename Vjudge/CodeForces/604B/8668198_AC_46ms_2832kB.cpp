#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,k,a[mx+5],cs[mx+5];
bool check(int x)
{
    int cnt=0;
    int lf=1;
    int rg=n;
    while(lf<=rg)
    {
        if(a[lf]+a[rg]<=x){
            lf++; rg--;
        }
        else {
              if(a[rg]>x)return false;
              rg--;
        }

        cnt++;
        if(cnt>k)return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&k);

    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    int lo=0;
    int hi=20000000;
    int ans;

    while(lo<=hi)
    {
        int md=(lo+hi)/2;

        if(check(md)){ans=md; hi=md-1;}
        else lo=md+1;
    }

    printf("%d\n",ans);

    return 0;
}
