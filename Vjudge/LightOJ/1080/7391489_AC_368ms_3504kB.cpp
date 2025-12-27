#include<bits/stdc++.h>
using namespace std;
#define mx 100005
string ss;
int tree[mx*4];
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd]=ss[b]-'0';
        return;
    }

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);
}
void update(int nd,int b,int e,int x,int y)
{
    if(y<b || x>e) return;
    if(b>=x&&e<=y){
        tree[nd]=tree[nd]^1;
        return;
    }

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;
    update(lf,b,md,x,y);
    update(rg,md+1,e,x,y);
}
int query(int nd,int b,int e,int x,int carry)
{
    if(b==x&&e==x)
        return carry^tree[nd];

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    if(x<=md)
        query(lf,b,md,x,carry^tree[nd]);
    else
        query(rg,md+1,e,x,carry^tree[nd]);
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        printf("Case %d:\n",ks);
        cin>>ss;
        int n=ss.size();

        memset(tree,0,sizeof(tree));
        init(1,0,n-1);

        int q;
        scanf("%d",&q);

        for(int i=1; i<=q; i++)
        {
            getchar();
            char ch;
            scanf("%c ",&ch);

            if(ch=='I')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x--;y--;
                update(1,0,n-1,x,y);
            }
            else
            {
                int x;
                scanf("%d",&x);
                x--;
                int ans=query(1,0,n-1,x,0);

                printf("%d\n",ans);
            }
        }
    }

    return 0;
}
