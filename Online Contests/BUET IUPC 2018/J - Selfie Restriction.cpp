#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dt{
    int x,y,z,s,i;
}rule[10005];
int a[305],sum[305];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,m; scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            rule[i].x = x;
            rule[i].y = y;
            rule[i].z = z;
            rule[i].i = 0;
            rule[i].s = 0;
        }

        memset(a,0,sizeof(a));
        for(int i=1; i<=m; i++){
            int x; scanf("%d",&x);
            a[x]++;
        }

        sum[0] = 0;
        for(int i=1; i<=300; i++){
            sum[i] = sum[i-1]+a[i];
        }

        ll ans = 0;
        for(int i=1; i<=300; i++){
            for(int k=1; k<=n; k++){
                rule[k].s += a[i];
            }
            for(int k=1; k<=n; k++){
                rule[k].i++;
                if(rule[k].s>rule[k].x){
                    ans += (rule[k].s/(rule[k].x+1))*rule[k].z;
                    rule[k].s = 0;
                    rule[k].i = 0;
                }
                else if(rule[k].i==rule[k].y){
                    int v = sum[i]-sum[i-rule[k].y];
                    if(v!=rule[k].s){
                        while(1){

                        }
                    }
                    rule[k].s = sum[i]-sum[i-rule[k].y+1];
                    rule[k].i--;
                }
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
