#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define LI long int
LI tree[mx*3];
char str[100000];
void init(LI node, LI b, LI e)
{
    if(b==e){
        tree[node]=str[b]-'0';
        return;
    }

    LI mid=(b+e)/2;
    init(node*2,b,mid);
    init(node*2+1,mid+1,e);
    tree[node]=0;
}
void update(LI node,LI b,LI e,LI i,LI j)
{
    if(b>j || e<i)
        return;
    if(b>=i && e<=j)
    {
        tree[node] ^=1;
        return;
    }
    LI mid=(b+e)/2;
    update(node*2,b,mid,i,j);
    update(node*2+1,mid+1,e,i,j);
}
int query(LI node,LI b,LI e,LI pos)
{
    if(pos<b || pos>e)
        return 0;
    if(pos==b && pos==e){
        return tree[node];
    }
    LI mid=(b+e)/2;
    if(pos<=mid){
        return query(node*2,b,mid,pos)^tree[node];
    }
    else{
        return query(node*2+1,mid+1,e,pos)^tree[node];
    }

}
int main()
{
    LI T,i,j,N,q,k,test;
    char ch;
    scanf("%ld",&T);

    for(test=1; test<=T; test++)
    {
        printf("Case %ld:\n",test);
        scanf("%s",str);
        N=strlen(str);
        init(1,0,N-1);

        scanf("%ld",&q);
        for(k=1; k<=q; k++)
        {
            getchar();
            scanf("%c",&ch);
            if(ch=='I')
            {
                scanf("%ld %ld",&i,&j);
                update(1,0,N-1,i-1,j-1);
            }
            else
            {
                scanf("%ld",&i);
                int res=query(1,0,N-1,i-1);
                printf("%d\n",res);
            }
        }
    }

    return 0;
}

