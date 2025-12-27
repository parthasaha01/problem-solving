#include<bits/stdc++.h>
using namespace std;
vector<int>dis[3005];
struct dt{
    int x,y;
}st[3005];
int main()
{
    int n,q;

    while(scanf("%d%d",&n,&q)==2)
    {
        if(n==0&&q==0) break;

        for(int i=1; i<=n; i++){
            scanf("%d%d",&st[i].x,&st[i].y);
        }

        for(int i=1; i<=n; i++){
            int sx = st[i].x;
            int sy = st[i].y;
            for(int j=1; j<=n; j++){
                int dx = st[j].x;
                int dy = st[j].y;
                int ds = (sx-dx)*(sx-dx) + (sy-dy)*(sy-dy);
                dis[i].push_back(ds);
            }
        }

        for(int i=1; i<=n; i++){
            sort(dis[i].begin(),dis[i].end());
        }

        for(int j=1; j<=q; j++){
            int r;
            scanf("%d",&r);
            r = r*r;
            double ans=0.0;
            for(int i=1; i<=n; i++){
                int cnt = upper_bound(dis[i].begin(),dis[i].end(),r)-dis[i].begin();
                ans += cnt;
            }
            ans /= (double)n;
            printf("%.2lf\n",ans);
        }
        printf("\n");
        for(int i=1; i<=n; i++) dis[i].clear();
    }
    return 0;
}
