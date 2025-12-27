#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int BLOCK_SIZE;
int N,n,q;
int aa[MAXN],bb[MAXN],vv[MAXN],last[MAXN],ans[MAXN],tree[MAXN];
map<int,int>mp;
//struct qur{
//    int l,r,t,k,id;
//}
struct qur {
	int l, r, t, k, id, blcl, blcr;
	qur(int _l, int _r, int _t, int _k, int _id) {
		l = _l, r = _r;
		t = _t, k = _k, id=_id;
		blcl = l / BLOCK_SIZE;
		blcr = r / BLOCK_SIZE;
	}
	bool operator < (const qur &p) const {
		if(blcl != p.blcl) return l < p.l;
		if(blcr != p.blcr) return r < p.r;
		return t < p.t;
	}
};
vector<qur>qr;
struct upd{
    int x, pre, now;
};
vector<upd>up;
//bool cmp(qur &a, qur &b)
//{
//    int l1 = (a.l/BLOCK_SIZE)+1;
//    int l2 = (b.l/BLOCK_SIZE)+1;
//    int r1 = (a.r/BLOCK_SIZE)+1;
//    int r2 = (b.r/BLOCK_SIZE)+1;
//
//    if(l1!=l2)return l1<l2;
//    if(r1!=r2)return r1<r2;
//    return a.t < b.t;
//}
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
    if(x>=l && y<=r)
    {
        Remove(x);
        aa[x] = y;
        Add(x);
    }
    else{
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

        for(int i=0; i<n; i++)
        {
            scanf("%d",&aa[i]);
            bb[i]=aa[i];
        }

        sort(bb,bb+n);

        mp.clear();
        int k=0;
        for(int i=0; i<n; i++)
        {
            if(mp.find(bb[i])==mp.end())
            {
                mp[bb[i]]=++k;
                vv[k] = bb[i];
            }
        }
        N = k;

        for(int i=0; i<n; i++){
            aa[i] = mp[aa[i]];
        }

        for(int i=0; i<n; i++){
            last[i] = aa[i];
        }

       // int idx = 0;
        //int id = 0;
        qr.clear();
        up.clear();
        up.push_back({-1, -1, -1});

        for(int i=0; i<q; i++)
        {
            getchar();
            char ch;
            scanf("%c",&ch);
            //printf("%c\n",ch);
            if(ch=='Q')
            {
                int l,r,k;
                scanf("%d%d%d",&l,&r,&k);
                l--; r--;
                qr.push_back(qur(l,r,up.size()-1,k,qr.size()));
                //++id;
//                qr[id].l = l;
//                qr[id].r = r;
//                qr[id].t = idx;
//                qr[id].k = k;
//                qr[id].id = id;
            }
            else
            {
                int x; scanf("%d",&x);
                x--;
                int y1 = last[x+1];
                int y2 = last[x];
                up.push_back({x,last[x],y1});
                last[x] = y1;
//                ++idx;
//                up[idx].x = x;
//                up[idx].pre = last[x];
//                up[idx].now = y1;
//                last[x] = y1;
                up.push_back({x+1,last[x+1],y2});
                last[x+1] = y2;
//                ++idx;
//                up[idx].x = x+1;
//                up[idx].pre = last[x+1];
//                up[idx].now = y2;
//                last[x+1] = y2;
            }

        }

        sort(qr.begin(),qr.end());

        int l=0, r = -1, t = 0;

        memset(tree,0,sizeof(tree));

        //printf("partha\n");

        for(int i=0; i<qr.size(); i++)
        {
            while(t<qr[i].t){
                ++t; apply(up[t].x, up[t].now, l, r);
            }
            while(t>qr[i].t){
                apply(up[t].x, up[t].pre, l, r); --t;
            }

            //printf("i=%d l=%d r=%d\n",i,l,r);

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

            ans[qr[i].id] = solve(qr[i].l,qr[i].r,qr[i].k);

            //printf("i=%d ans=%d\n",i,ans[qr[i].id]);
        }

        for(int i=0; i<qr.size(); i++){
            printf("%d\n",vv[ans[i]]);
        }

    }
    return 0;
}

