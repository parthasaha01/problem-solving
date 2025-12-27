#include<bits/stdc++.h>
using namespace std;
struct dt{
    int x,y;
}dust[50005];
bool cmp(dt a,dt b){
    return a.y<b.y;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n,w;
        scanf("%d%d",&n,&w);

        for(int i=0; i<n; i++){
            scanf("%d%d",&dust[i].x,&dust[i].y);
        }

        sort(dust,dust+n,cmp);

        int ans=1;
        int pos=dust[0].y+w;
        for(int i=0; i<n; i++){
            if(dust[i].y>pos){
                ans++;
                pos=dust[i].y+w;
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
