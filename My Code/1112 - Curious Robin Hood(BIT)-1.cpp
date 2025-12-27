#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,q,a[mx],tree[mx];
int update(int idx,int v)
{
    while(idx<=n){
        tree[idx] += v;
        idx += idx & (-idx);
    }
}
int query(int idx)
{
    int sum = 0;
    int x = 1;
    while(x<=idx){
        int log = (int)log2(idx-x+1);
        sum += tree[x+(1<<log)-1];
        x += (1<<log);
    }
    return sum;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        memset(tree,0,sizeof(tree));

        printf("Case %d:\n",ks);
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        for(int i=1; i<=n; i++)update(i,a[i]);

        while(q--)
        {
            int tp; scanf("%d",&tp);

            if(tp==1){
                int idx; scanf("%d",&idx);
                int v = query(idx+1) - query(idx);
                printf("%d\n",v);
                update(idx+1,-v);
            }
            else if(tp==2){
                int idx,v; scanf("%d%d",&idx,&v);
                update(idx+1,v);
            }
            else{
                int idx1,idx2; scanf("%d%d",&idx1,&idx2);
                int v = query(idx2+1) - query(idx1);
                printf("%d\n",v);
            }
        }
    }
    return 0;
}

