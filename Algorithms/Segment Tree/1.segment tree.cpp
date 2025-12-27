#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
int tree[mx*4];
void init(int node, int b, int e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int i,int x)
{
    if(b>i || e<i)
        return;
    if(b==e){
        tree[node]=x;
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
        return tree[node];

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return p1+p2;
}
int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        printf("\nCase %d:\n",test);

        int N;
        printf("Enter the number of element: ");
        scanf("%d",&N);

        printf("Enter all the elements:\n");
        for(int k=1; k<=N; k++)
            scanf("%d",&arr[k]);

        init(1,1,N);

        int Q;
        printf("Enter number of query and update: ");
        scanf("%d",&Q);

        printf("Enter all the queries and updates:\n");

        for(int q=1; q<=Q; q++)
        {
            char ch;
            int i,j;
            cin >> ch >> i >> j;

            if(ch=='q' || ch == 'Q'){
                int sum = query(1,1,N,i,j);
                printf("sum=%d\n",sum);
            }
            else{
                update(1,1,N,i,j);
            }
        }
    }

    return 0;
}
