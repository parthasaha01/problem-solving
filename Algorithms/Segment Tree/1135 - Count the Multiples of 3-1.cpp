#include <bits/stdc++.h>
using namespace std;
#define mx    100009
struct info
{
    int zero,one,two,lazy;
}tree[6*mx];

void update_lazy(int node)
{
    int temp = tree[node].zero;
    tree[node].zero=tree[node].two;
    tree[node].two=tree[node].one;
    tree[node].one=temp;
}

void update_node(int node,int left)
{
    tree[left].lazy +=  tree[node].lazy;
    tree[left+1].lazy +=  tree[node].lazy;

    tree[node].lazy%=3;
    int shift = tree[node].lazy;
    while(shift)
    {
        update_lazy(left);
        update_lazy(left+1);
        shift--;
    }
    tree[node].lazy=0;
}

void marge(int node, int left, int right)
{
    tree[node].zero = tree[left].zero+tree[right].zero;
    tree[node].one  = tree[left].one+tree[right].one;
    tree[node].two  = tree[ left].two+tree[right].two;
}

void make(int node, int s, int e)
{
   if(s==e)
   {
        tree[node].lazy=0;
        tree[node].one=0;
        tree[node].two=0;
        tree[node].zero=1;
        return;
   }

   int left=node<<1;
   int mid=(s+e)>>1;

    make(left,s,mid);
    make(left+1,mid+1,e);

    marge(node,left,left+1);
}

void update(int node,int b,int e,int i,int j)
{
   if(b==i && e==j){
       tree[node].lazy++;
       update_lazy(node);
       return;
   }

   int left=node<<1;
   int mid=(b+e)>>1;

   if(tree[node].lazy!=0){
       update_node(node,left);
   }

   if(j<=mid){
        update(left,b,mid,i,j);
   }
   else if(i>mid){
       update(left+1,mid+1,e,i,j);
   }
   else{
       update(left,b,mid,i,mid);
       update(left+1,mid+1,e,mid+1,j);
   }
   marge(node,left,left+1);
}

int query(int node,int b,int e,int i,int j)
{
    if(b==i&&e==j)return tree[node].zero;

    int left=node<<1;
    int mid=(b+e)>>1;

    if(tree[node].lazy){
        update_node(node,left);
    }

    if(j<=mid)
        return query(left, b, mid, i, j);
    else if(i>mid)
        return query(left+1, mid+1, e, i, j);
    else{
        int p1 = query(left, b, mid, i, mid);
        int p2 = query(left+1, mid+1, e, mid+1, j);
        return p1+p2;
    }
}
int main()
{
    int t,no=0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++no);
        int n,q,a;
        scanf("%d %d",&n,&q);

        memset(tree,0,sizeof(tree));
        make(1,1,n);

        while(q--)
        {
            int type,l,r;
            scanf("%d %d %d",&type,&l,&r);
            l++;r++;

            if(type == 0){
                update(1,1,n,l,r);
            }
            else{
                printf("%d\n",query(1,1,n,l,r));
            }
        }
    }
    return 0;
}
