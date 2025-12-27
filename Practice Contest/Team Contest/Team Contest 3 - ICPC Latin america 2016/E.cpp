#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int BLOCK_SIZE;
int N,n,q;
int aa[MAXN],bb[MAXN],vv[MAXN],last[MAXN],ans[MAXN],tree[MAXN];
map<int,int>mp;
struct qur{
    int l,r,t,k,id;
}qr[MAXN];
struct upd{
    int x, pre, now;
}up[MAXN];
bool cmp(qur &a, qur &b)
{
    int l1 = (a.l/BLOCK_SIZE)+1;
    int l2 = (b.l/BLOCK_SIZE)+1;
    int r1 = (a.r/BLOCK_SIZE)+1;
    int r2 = (b.r/BLOCK_SIZE)+1;

    if(l1!=l2)return l1<l2;
    if(r1!=r2)return r1<r2;
    return a.t < b.t;
}
void update(int idx,int v)
{
    while(idx<=N)
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
void Add(int x)
{
    update(aa[x],+1);
}
void Remove(int x)
{
    update(aa[x],-1);
}
void apply(int x,int y,int l,int r)
{

    if(x>=l && x<=r)
    {
        //printf("apply x=%d y=%d l=%d r=%d a[x]=%d\n",x,y,l,r,aa[x]);
        Remove(x);
        aa[x] = y;
        Add(x);
    }
    else{
        //printf("apply nai x=%d y=%d l=%d r=%d a[x]=%d\n",x,y,l,r,aa[x]);
        aa[x] = y;
    }
}
int solve(int l, int r,int k)
{
    int lo = 1;
    int hi = N;
    int ret;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int sum = query(md);

        if(sum>=k){
            ret = md;
            hi = md-1;
        }
        else{
            lo=md+1;
        }
    }
    return ret;
}
int main()
{
    while(scanf("%d%d",&n,&q)==2)
    {
        BLOCK_SIZE = (int)pow(n, 0.6667);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&aa[i]);
            bb[i]=aa[i];
        }

        sort(bb+1,bb+n+1);

        mp.clear();
        int k=0;
        for(int i=1; i<=n; i++)
        {
            if(mp.find(bb[i])==mp.end())
            {
                mp[bb[i]]=++k;
                vv[k] = bb[i];
            }
        }
        N = k;

        for(int i=1; i<=n; i++){
            aa[i] = mp[aa[i]];
        }

        for(int i=1; i<=n; i++){
            last[i] = aa[i];
        }

        int idx = 1;
        int id = 0;
        for(int i=1; i<=q; i++)
        {
            getchar();
            char ch;
            scanf("%c",&ch);
            //printf("%c\n",ch);
            if(ch=='Q')
            {
                int l,r,k;
                scanf("%d%d%d",&l,&r,&k);
                ++id;
                qr[id].l = l;
                qr[id].r = r;
                qr[id].t = idx;
                qr[id].k = k;
                qr[id].id = id;
            }
            else
            {
                int x; scanf("%d",&x);
                int y1 = last[x+1];
                int y2 = last[x];
                ++idx;
                up[idx].x = x;
                up[idx].pre = last[x];
                up[idx].now = y1;
                last[x] = y1;

                ++idx;
                up[idx].x = x+1;
                up[idx].pre = last[x+1];
                up[idx].now = y2;
                last[x+1] = y2;
            }

        }

        sort(qr+1,qr+id+1,cmp);

        int l=1, r = 0, t = 1;

        memset(tree,0,sizeof(tree));

        //printf("partha\n");

        for(int i=1; i<=id; i++)
        {
//            for(int i=1; i<=n; i++){
//                printf("%d ",vv[aa[i]]);
//            }
//            printf("\n");
            while(t<qr[i].t){
                ++t; apply(up[t].x, up[t].now, l, r);
            }
            while(t>qr[i].t){
                apply(up[t].x, up[t].pre, l, r); --t;
            }

//            for(int i=1; i<=n; i++){
//                printf("%d ",aa[i]);
//            }
//            printf("\n");
//            for(int w=1; w<=N; w++){
//                printf("%d ",query(w)-query(w-1));
//            }
//            printf("\n");
//            for(int i=1; i<=n; i++){
//                printf("%d ",vv[aa[i]]);
//            }
//            printf("\n\n");

//            printf("i=%d l=%d r=%d ql=%d qr=%d\n",i,l,r, qr[i].l, qr[i].r);

            while(l>qr[i].l){
                //printf("1 - i=%d l=%d r=%d ql=%d qr=%d\n",i,l,r, qr[i].l, qr[i].r);
                Add(--l);
            }
            while(r<qr[i].r) {
                //printf("2 - i=%d l=%d r=%d ql=%d qr=%d\n",i,l,r, qr[i].l, qr[i].r);
                Add(++r);
            }
            while(l<qr[i].l) {
                //printf("3 - i=%d l=%d r=%d ql=%d qr=%d\n",i,l,r, qr[i].l, qr[i].r);
                Remove(l++);
            }
            while(r>qr[i].r) {
                //printf("4 - i=%d l=%d r=%d ql=%d qr=%d\n",i,l,r, qr[i].l, qr[i].r);
                Remove(r--);
            }

//            for(int w=1; w<=N; w++){
//                printf("%d ",query(w)-query(w-1));
//            }
//            printf("\n\n");

            ans[qr[i].id] = solve(qr[i].l,qr[i].r,qr[i].k);

            //printf("i=%d ans=%d\n",i,ans[qr[i].id]);
        }

        for(int i=1; i<=id; i++){
            printf("%d\n",vv[ans[i]]);
        }

    }
    return 0;
}
