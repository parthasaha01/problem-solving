#include<bits/stdc++.h>
using namespace std;
#define mx 150005
struct dt
{
    int x,y;
}seg[mx];
int tree[4*mx];
int qer[mx];
int ans;
void update(int node,int b,int e,int x,int y,int lazy)
{
    if(lazy!=0){
        tree[node]+=lazy;
    }

    if(e<x||b>y){
        return;
    }
    if(b>=x&&e<=y){
        tree[node]+=1;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    update(left,b,mid,x,y,tree[node]);
    update(right,mid+1,e,x,y,tree[node]);
    tree[node]=0;
}
void query(int node,int b,int e,int x,int lazy)
{

    if(b==x&&e==x){
        ans=tree[node]+lazy;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    if(x<=mid){
        query(left,b,mid,x,lazy+tree[node]);
    }
    else{
        query(right,mid+1,e,x,lazy+tree[node]);
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        printf("Case %d:\n",kase);

        int n,q;
        scanf("%d%d",&n,&q);

        set<int>ss;

        for(int i=1; i<=n; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            seg[i].x=x;
            seg[i].y=y;
            ss.insert(x);
            ss.insert(y);
        }

        for(int i=1; i<=q; i++){
            int x;
            scanf("%d",&x);
            qer[i]=x;
            ss.insert(x);
        }

        set<int>::iterator it;
        map<int,int>mp;
        int k=0;
        for(it=ss.begin(); it!=ss.end(); it++){
            //printf("%d ",*it);
            mp[*it]=++k;
        }

        int sz=ss.size();
        memset(tree,0,sizeof(tree));
        //printf("\nsz=%d\n",sz);

        for(int i=1; i<=n; i++)
        {
            int x=mp[seg[i].x];
            int y=mp[seg[i].y];

           // printf("\nupdate x=%d y=%d\n",x,y);

            update(1,1,sz,x,y,0);

            /*for(int k=1; k<=4*sz; k++){
                if(tree[k]!=0){
                    printf("tree[%d]=%d\n",k,tree[k]);
                }
            }*/
        }

        for(int i=1; i<=q; i++)
        {
            int x=mp[qer[i]];
            //printf("query x=%d\n",x);
            query(1,1,sz,x,0);
            printf("%d\n",ans);
        }
    }

    return 0;
}
/*
1
21 4

19 31
0 8
11 28
7 29
15 17
26 33
1 5
1 23
2 5
29 37
18 22
33 37
1 9
4 37
8 10
16 21
16 31
12 21
10 20
19 27
4 19
13
16
5
37

*/
