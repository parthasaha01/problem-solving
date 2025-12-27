#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,t,a[mx+5],cs[mx+5];
bool check(int x)
{
    for(int i=x; i<=n; i++){
        if(cs[i]-cs[i-x]<=t)return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&t);

    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)cs[i]=cs[i-1]+a[i];

    int lo=0;
    int hi=n;
    int ans;

    while(lo<=hi)
    {
        int md=(lo+hi)/2;

        if(check(md)){ans=md; lo=md+1;}
        else hi=md-1;
    }

    printf("%d\n",ans);

    return 0;
}
