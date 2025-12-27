#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 150000
ll tree[mx*4+5];
ll a[mx+5],ans;
void init(int node,int b,int e,int n)
{
    if(b==e){
        if(b<=n)
            tree[node]=1;
        else
            tree[node]=0;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid,n);
    init(right,mid+1,e,n);

    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int x)
{
    if(e<x||b>x)
        return;

    if(b==e&&x==b){
        tree[node]=1;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    update(left,b,mid,x);
    update(right,mid+1,e,x);

    tree[node]=tree[left]+tree[right];
}
void query(int node,int b,int e,int x)
{
    if(b==e){
        ans=a[b];
        tree[node]=0;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    if(tree[left]>=x){
        query(left,b,mid,x);
    }
    else{
        query(right,mid+1,e,x-tree[left]);
    }

    tree[node]=tree[left]+tree[right];
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

        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }

        init(1,1,mx,n);

        for(int i=0; i<q; i++)
        {
            char ch;
            ll v;

            getchar();
            scanf("%c %lld",&ch,&v);

            if(ch=='a')
            {
                n++;
                a[n]=v;
                update(1,1,mx,n);
            }
            else
            {
                if(tree[1]<v){
                    printf("none\n");
                }
                else{
                    query(1,1,mx,v);
                    printf("%lld\n",ans);
                }
            }
        }
    }

    return 0;
}
