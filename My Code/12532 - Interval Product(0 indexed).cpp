#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx],block[1005],zero[1005],neg[1005],pos[1005];
int blk_sz,blk_cnt;
void update(int idx,int v)
{
    int cur = idx/blk_sz;

    if(a[idx]==0) zero[cur]--;
    if(a[idx]<0) neg[cur]--;

    if(zero[cur]>0)block[cur]=0;
    else if(neg[cur]%2==1)block[cur]=-1;
    else block[cur]=1;

    block[cur] *= v;
    a[idx]=v;

    if(v==0)zero[cur]++;
    if(v<0)neg[cur]++;
}
int query(int x,int y)
{
    int sum = 1;
    while(x<=y && (x%blk_sz !=0))
    {
        sum *= a[x];
        x++;
    }
    while((x+blk_sz-1) <= y)
    {
        int cur = x/blk_sz;
        sum *= block[cur];
        x += blk_sz;
    }
    while(x<=y)
    {
        sum *= a[x];
        x++;
    }
    return sum;
}
void preprocess(int n)
{
    blk_sz = sqrt(n);

    int blk_idx = -1;
    for(int i=0; i<=1000; i++)block[i]=1;
    memset(zero,0,sizeof(zero));
    memset(neg,0,sizeof(neg));

    for(int i=0; i<n; i++){
        if(i%blk_sz==0)blk_idx++;
        block[blk_idx]*= a[i];
        if(a[i]==0)zero[blk_idx]++;
        if(a[i]<0)neg[blk_idx]++;
    }
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            if(a[i]<0)a[i]=-1;
            else if(a[i]>0)a[i]=1;
            else a[i]=0;
        }

        preprocess(n);

        while(q--)
        {
            getchar();
            char tp; scanf("%c",&tp);
            //printf("tp=%c\n",tp);
            if(tp=='P')
            {
                int x,y; scanf("%d%d",&x,&y);

                int sum = query(--x,--y);

                //printf("tp=%c x=%d y=%d sum=%d\n",tp,x,y,sum);
                if(sum==0)printf("0");
                if(sum==1)printf("+");
                if(sum==-1)printf("-");
            }
            else
            {

                int x,v;
                scanf("%d%d",&x,&v);
                //printf("tp=%c x=%d v=%d\n",tp,x,v);
                if(v<0)v=-1;
                else if(v>0)v=1;
                else v=0;
                update(--x,v);
            }
        }
        printf("\n");
    }

    return 0;
}


