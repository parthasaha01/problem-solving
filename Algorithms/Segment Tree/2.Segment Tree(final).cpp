#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define LI long int
LI arr[mx];
LI tree[mx*4];
void init(LI node, LI b, LI e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }

    LI left=node*2;
    LI right=left+1;
    LI mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void update(LI node,LI b,LI e,LI i,LI x)
{
    if(b>i || e<i)
        return;
    if(b==e)
    {
        tree[node]=x;
        return;
    }

    LI left=node*2;
    LI right=left+1;
    LI mid=(b+e)/2;

    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[node]=tree[left]+tree[right];
}
LI query(LI node,LI b,LI e,LI i,LI j)
{
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
        return tree[node];

    LI left=node*2;
    LI right=left+1;
    LI mid=(b+e)/2;

    LI p1 = query(left,b,mid,i,j);
    LI p2 = query(right,mid+1,e,i,j);
    return p1+p2;
}
int main()
{
    LI T,N,Q,test,i,j,k,q;
    char ch;

    printf("Enter the number of test cases: ");
    scanf("%ld",&T);
    for(test=1; test<=T; test++)
    {
        printf("\nCase %ld:\n",test);
        printf("Enter the number of element: ");
        scanf("%ld",&N);

        printf("Enter all the elements:\n");
        for(k=1; k<=N; k++)
            scanf("%ld",&arr[k]);

        init(1,1,N);

        printf("Enter number of query and update: ");
        scanf("%ld",&Q);
        printf("Enter all the queries and updates:\n");
        for(q=1; q<=Q; q++)
        {
            cin >> ch >> i >> j;

            if(ch=='q' || ch == 'Q')
            {
                LI sum = query(1,1,N,i,j);
                printf("sum=%ld\n",sum);
            }
            else
            {
                update(1,1,N,i,j);
            }
        }
    }

    return 0;
}

