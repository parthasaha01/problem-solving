#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,hx,hy;
ll fun(int x, int y, ll w)
{
    int xx,yy;

    if(x<=n){
        xx = x-y+1;
        yy = y;
    }
    else{
        xx = n-y+1;
        yy = x+y-n;
    }

    int ds = abs(hx-xx)+abs(hy-yy);

    if(ds&1)return w;
    else return 0;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d%d",&n,&m);

        int sx,sy; scanf("%d%d",&sx,&sy);

        if(sx<=n){
            hx = sx-sy+1;
            hy = sy;
        }
        else{
            hx = n-sy+1;
            hy = sx+sy-n;
        }

        ll ans=0;
        for(int i=1; i<=m; i++){
            ll w;
            int x,y; scanf("%d%d%lld",&x,&y,&w);
            ans ^= fun(x,y,w);
        }

        if(ans)printf("Case %d: Dasia wins! :D\n",ks);
        else   printf("Case %d: Tutu wins -_-\n",ks);
    }

    return 0;
}

/*
3

3 3
3 2
4 1 3
1 1 2
2 1 5

3 5
3 2
3 1 5
4 2 6
2 2 7
3 3 8
2 1 4

4 9
3 2
5 2 55
4 4 45
1 1 21
4 2 18
7 1 11
2 2 13
6 2 41
5 3 62
4 1 27
*/
