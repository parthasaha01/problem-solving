#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
#define mx 100005
long int arr[mx];
long int tree[mx*3];
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
    tree[node]=min(tree[left],tree[right]);
}
long int query(long int node,long int b,long int e,long int i,long int j)
{
    if(b>j || e<i){
        return INF;
    }
    if(b>=i && e<=j){
        return tree[node];
    }
    long int left=node*2;
    long int right=left+1;
    long int mid = (b+e)/2;
    long int m1=query(left,b,mid,i,j);
    long int m2=query(right,mid+1,e,i,j);
    return min(m1,m2);
}
int main()
{
    long int T,N,Q,i,j,k,q,test,Min;
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
            scanf("%ld %ld",&i,&j);
            Min=query(1,1,N,i,j);
            printf("%ld\n",Min);
        }
    }

    return 0;
}
