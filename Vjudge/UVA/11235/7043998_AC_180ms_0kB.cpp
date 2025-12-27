#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx],tree[4*mx];
map<int,int>mp;
void init(int n,int b,int e)
{
    if(b==e){
        tree[n]=mp[a[b]];
        return;
    }

    int l=2*n;
    int r=2*n+1;
    int m=(b+e)/2;

    init(l,b,m);
    init(r,m+1,e);
    tree[n]=max(tree[l],tree[r]);
}
int query(int n,int b,int e,int x,int y)
{
    if(e<x||b>y)
        return 0;

    if(b>=x&&e<=y)
        return tree[n];

    int l=2*n;
    int r=2*n+1;
    int m=(b+e)/2;

    return max(query(l,b,m,x,y),query(r,m+1,e,x,y));
}
int main()
{
    int n;
    while(scanf("%d",&n)&& n)
    {
        mp.clear();
        //memset(tree,0,sizeof(tree));
        int q;
        scanf("%d",&q);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }

        init(1,1,n);

        for(int i=1; i<=q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            int maxx=1;

            if(a[x]==a[y]){
                maxx=y-x+1;
                printf("%d\n",maxx);
                continue;
            }

            x++;
            int cx=1;
            while(x<=y){
                if(a[x]==a[x-1]){
                    cx++;
                    x++;
                }
                else
                    break;
            }

            y--;
            int cy=1;
            while(y>=x){
                if(a[y]==a[y+1]){
                    cy++;
                    y--;
                }
                else
                    break;
            }

            maxx=max(cx,cy);

            if(x>=y){
                printf("%d\n",maxx);
                continue;
            }

            maxx=max(maxx,query(1,1,n,x,y));

            printf("%d\n",maxx);
        }
    }

    return 0;
}
