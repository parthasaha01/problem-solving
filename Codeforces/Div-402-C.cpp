#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int a[mx+5],b[mx+5];
struct dt
{
    int df;
    int id;
}d[mx+5];
bool cmp(dt x,dt y){
    return x.df<y.df;
}
int main()
{
    int n,k;

    while(cin>>n>>k)
    {
        int sum = 0;

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }
        for(int i=1; i<=n; i++){
            scanf("%d",&b[i]);
        }

        for(int i=1; i<=n; i++){
            d[i].df = a[i]-b[i];
            d[i].id = i;
        }



        sort(d+1,d+n+1,cmp);

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(i>k && d[i].df>0){
                for(int j=i; j<=n; j++){
                    ans += b[d[j].id];
                }
                break;
            }

            ans += a[d[i].id];
        }

        printf("%d\n",ans);
    }

    return 0;
}
