#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define LI long int
LI arr[mx];
LI tree[mx*3];
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
    char s[25];
    test=0;
    while(scanf("%ld",&N)==1 && N)
    {
        if(test!=0)
            printf("\n");
        printf("Case %ld:\n",++test);

        for(k=1; k<=N; k++)
            scanf("%ld",&arr[k]);

        init(1,1,N);

        while(1)
        {
            //printf("partha\n");
            //getchar();
            scanf("%s",&s);
            //printf("*%s*\n",s);
            if(strcmp(s,"END")==0){
                break;
            }

            scanf("%ld %ld",&i,&j);

            if(s[0]=='S')
            {
                update(1,1,N,i,j);
            }
            else if(s[0]=='M')
            {
                LI sum = query(1,1,N,i,j);
                printf("%ld\n",sum);
            }

        }

    }

    return 0;
}
