#include<bits/stdc++.h>
using namespace std;
#define mx 100005
long int arr[mx];
long int tree[mx*3];
long int s;
void init(long int node,long int b,long int e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    long int left=node*2;
    long int right=left+1;
    long int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
long int query(long int node,long int b,long int e,long int i,long int j)
{
    if(b>j || e<i){
        return 0;
    }
    if(b>=i && e<=j){
        return tree[node];
    }
    long int left=node*2;
    long int right=left+1;
    long int mid = (b+e)/2;
    long int p1=query(left,b,mid,i,j);
    long int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
void update(long int node,long int b,long int e,long int i,long int newvalue)
{
    if(b>i || e<i){
        return ;
    }
    if(b==e)
    {
        if(newvalue==0){
            if(b==i)
                s=tree[node];
            tree[node]=0;
        }
        else{
            tree[node]+=newvalue;
        }
        return;
    }
    long int left=node*2;
    long int right=left+1;
    long int mid = (b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    long int T,N,Q,i,j,k,q,test,Min,ch,newvalue;
    scanf("%ld",&T);

    for(test=1; test<=T; test++)
    {
        printf("Case %ld:\n",test);
        scanf("%ld %ld",&N,&Q);

        for(k=1; k<=N; k++){
            scanf("%ld",&arr[k]);
        }
        init(1,1,N);

        for(q=1; q<=Q; q++)
        {
            scanf("%ld",&ch);
            if(ch==1){
                scanf("%ld",&i);
                update(1,1,N,i+1,0);
                printf("%ld\n",s);
            }
            else if(ch==2)
            {
                scanf("%ld %ld",&i,&newvalue);
                update(1,1,N,i+1,newvalue);
            }
            else
            {
               scanf("%ld %ld",&i,&j);
               Min=query(1,1,N,i+1,j+1);
               printf("%ld\n",Min);
            }



        }
    }

    return 0;
}
