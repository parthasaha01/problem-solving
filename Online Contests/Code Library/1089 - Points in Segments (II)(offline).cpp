#include<bits/stdc++.h>
using namespace std;
#define mx 150005
struct dt{
    int x,y;
}seg[mx];
int tree[8*mx],qer[mx],ans;

void update(int node,int b,int e,int x,int y,int lazy)
{
    if(lazy!=0) tree[node]+=lazy;

    if(e<x||b>y) return;

    if(b>=x&&e<=y){
        tree[node]+=1;
        return;
    }

    int left=node*2; int right=node*2+1; int mid=(b+e)/2;

    update(left,b,mid,x,y,tree[node]);
    update(right,mid+1,e,x,y,tree[node]);
    tree[node]=0;
}
void query(int node,int b,int e,int x)
{
    if(b==x&&e==x){
        ans=tree[node];
        return;
    }

    int left=node*2; int right=node*2+1; int mid=(b+e)/2;

    if(tree[node]!=0){
        tree[left]+=tree[node];
        tree[right]+=tree[node];
        tree[node]=0;
    }

    if(x<=mid)
        query(left,b,mid,x);
    else
        query(right,mid+1,e,x);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);

    set<int>ss;
    for(int i=1; i<=n; i++){
        scanf("%d%d",&seg[i].x,&seg[i].y);
        ss.insert(seg[i].x);
        ss.insert(seg[i].y);
    }

    for(int i=1; i<=q; i++){
        scanf("%d",&qer[i]);
        ss.insert(qer[i]);
    }

    set<int>::iterator it;
    map<int,int>mp;
    int k=0;
    for(it=ss.begin(); it!=ss.end(); it++){
        mp[*it]=++k;
    }

    int sz=ss.size();
    memset(tree,0,sizeof(tree));

    for(int i=1; i<=n; i++){
        int x=mp[seg[i].x];
        int y=mp[seg[i].y];
        update(1,1,sz,x,y,0);
    }

    for(int i=1; i<=q; i++)
    {
        int x=mp[qer[i]];
        query(1,1,sz,x);
        printf("%d\n",ans);
    }
    return 0;
}
