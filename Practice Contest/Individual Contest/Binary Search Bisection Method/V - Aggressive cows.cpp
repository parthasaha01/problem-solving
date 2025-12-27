#include<bits/stdc++.h>
using namespace std;
int n,c,a[100005];
bool check(int x)
{
    int cnt=1;
    int pr=a[1];
    for(int i=2; i<=n; i++){
        if(a[i]-pr>=x){
            cnt++;
            pr=a[i];
        }
        if(cnt>=c)return true;
    }

    return false;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&c);

        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);

        int lo=0;
        int hi=1000000005;
        int ans=0;

        while(lo<=hi)
        {
            int md = (lo+hi)/2;

            if(check(md)){ ans=md; lo=md+1;}
            else hi=md-1;
        }

        printf("%d\n",ans);
    }

    return 0;
}
