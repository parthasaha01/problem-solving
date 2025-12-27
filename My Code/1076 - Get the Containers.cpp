#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int maxx=0;
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            maxx=max(maxx,a[i]);
        }

        int lo=maxx;
        int hi=maxx*n;
        int ans=0;

        while(lo<=hi)
        {
            int md=(lo+hi)/2;
            int x=md;
            int cnt=1;
            for(int i=0; i<n; i++){
                if(x-a[i]>=0){
                    x-=a[i];
                }
                else{
                    cnt++;
                    x=md;
                    x-=a[i];
                }
            }

            if(cnt>m){
                lo=md+1;
            }
            else{
                hi=md-1;
                ans=md;
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
