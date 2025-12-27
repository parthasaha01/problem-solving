#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx],block[1005];
int blk_sz;
void update(int idx,ll v)
{
    int cur = idx/blk_sz;
    block[cur] -= a[idx];
    block[cur] += v;
    a[idx]=v;
}
ll query(int x,int y)
{
    ll sum = 0;
    while(x<=y && (x%blk_sz !=0))
    {
        sum += a[x];
        x++;
    }
    while((x+blk_sz-1) <= y)
    {
        int cur = x/blk_sz;
        sum += block[cur];
        x += blk_sz;
    }
    while(x<=y)
    {
        sum += a[x];
        x++;
    }
    return sum;
}
void preprocess(int n)
{
    int blk_idx=-1;
    blk_sz = sqrt(n);
    memset(block,0,sizeof(block));

    for(int i=0; i<n; i++){
        if(i%blk_sz==0)blk_idx++;
        block[blk_idx] += a[i];
    }

//    for(int k=0,i=0; k<blk_cnt && i<n; k++){
//        for(int j=1; j<=blk_sz && i<n; j++){
//            //if(i>=n)break;
//            block[k]+= a[i];
//            i++;
//        }
//    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);
        int n,q; scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++){
            scanf("%lld",&a[i]);
        }

        preprocess(n);


        while(q--)
        {
            int tp; scanf("%d",&tp);
            if(tp==1)
            {
                int x,y; scanf("%d%d",&x,&y);
                ll sum = query(x,y);
                printf("%lld\n",sum);
            }
            else
            {
                int x; ll v;
                scanf("%d%lld",&x,&v);
                update(x,v);
            }
        }
    }

    return 0;
}

