#include<bits/stdc++.h>
using namespace std;
const int BLOCK_SIZE=320;
int n,a[100005];
vector<int>block[325];
int fun(int id,int v)
{
    int lo = 0;
    int hi = block[id].size()-1;
    int cnt = 0;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(block[id][md]<v){
            cnt = md+1;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }
    return (int)block[id].size()-cnt;
}
int query(int l,int r,int v)
{
    int lb = l/BLOCK_SIZE;
    int rb = r/BLOCK_SIZE;

    int ans = 0;
    if(lb==rb){
        for(int i=l; i<=r; i++){
            if(a[i]>=v)ans++;
        }
        return ans;
    }

    int xx = ((lb+1)*BLOCK_SIZE)-1;
    for(int i=l; i<=xx; i++){
        if(a[i]>=v)ans++;
    }

    if(rb-lb>1){
        for(int i=lb+1; i<rb; i++){
            ans += fun(i,v);
        }
    }

    int yy = rb*BLOCK_SIZE;
    for(int i=yy; i<=r; i++){
        if(a[i]>=v)ans++;
    }

    return ans;
}
int main()
{
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    for(int i=0; i<n; i++){
        block[i/BLOCK_SIZE].push_back(a[i]);
    }

    for(int i=0; i<BLOCK_SIZE; i++){
        sort(block[i].begin(),block[i].end());
    }

    int q; scanf("%d",&q);

    while(q--)
    {
        int tp; scanf("%d",&tp);
        if(tp==0)
        {
            int l,r,v; scanf("%d%d%d",&l,&r,&v);
            l--,r--;
            int ans = query(l,r,v);
            printf("%d\n",ans);
        }
        else
        {
            int x,v; scanf("%d%d",&x,&v);
            x--;
            a[x] = v;
            int b = x/BLOCK_SIZE;
            int bg = b*BLOCK_SIZE;
            int ed = bg + block[b].size()-1;
            block[b].clear();
            for(int i=bg; i<=ed; i++){
                block[b].push_back(a[i]);
            }
            sort(block[b].begin(),block[b].end());
        }
    }
    return 0;
}
