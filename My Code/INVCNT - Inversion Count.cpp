#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int tree[mx],n,a[mx],b[mx],mp[mx];
void update(int idx,int v)
{
    while(idx<=n)
    {
        tree[idx]+=v;
        idx += (idx) & (-idx);
    }
}
int query(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx) & (-idx);
    }
    return sum;
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }

        sort(b+1,b+n+1);

        for(int i=1; i<=n; i++){
            mp[i] = (int)(lower_bound(b+1,b+n+1,a[i])-(b+1))+1;
        }

//        for(int i=0; i<n; i++){
//            printf("%d ",mp[i]);
//        }
//        printf("\n");

        memset(tree,0,sizeof(tree));
        long long int ans = 0;
        for(int i=n; i>0; i--)
        {
            ans += query(mp[i]);
            update(mp[i],1);
        }

        printf("%lld\n",ans);
    }
    return 0;
}
