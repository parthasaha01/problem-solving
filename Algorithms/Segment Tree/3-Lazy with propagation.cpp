#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
ll arr[mx];
struct info
{
    ll sum,prop;
}tree[mx*4];
void init(ll node,ll b,ll e)
{
    tree[node].prop=0;

    if(b==e){
        tree[node].sum=arr[b];
        return;
    }

    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(b>j || e<i)
        return;
    if(b>=i && e<=j){
        tree[node].sum += (e-b+1)*x;
        tree[node].prop += x;
        return;
    }

    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum = tree[left].sum+tree[right].sum+((e-b+1)*tree[node].prop);
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j){
        return tree[node].sum+((e-b+1)*carry);
    }

    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;

    ll p1 = query(left,b,mid,i,j,carry+tree[node].prop);
    ll p2 = query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p1+p2;
}
int main()
{
    ll T,test,N,Q,i,j,k,q,x;
    char ch;

    printf("Enter the number of test cases: ");
    scanf("%lld",&T);
    for(test=1; test<=T; test++)
    {
        printf("\nCase %lld:\n",test);
        printf("Enter the number of element: ");
        scanf("%lld",&N);

        printf("Enter all the elements:\n");
        for(k=1; k<=N; k++)
            scanf("%lld",&arr[k]);

        init(1,1,N);

        printf("Enter number of query and update: ");
        scanf("%lld",&Q);
        printf("Enter all the queries and updates:\n");
        for(q=1; q<=Q; q++)
        {
            cin >> ch;

            if(ch=='q' || ch == 'Q')
            {
                cin >> i >> j;
                ll sum = query(1,1,N,i,j,0);
                printf("sum=%lld\n",sum);
            }
            else
            {
                cin >> i >> j >> x;
                update(1,1,N,i,j,x);
            }
        }
    }

    return 0;
}
