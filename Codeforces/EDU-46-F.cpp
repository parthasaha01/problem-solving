#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500015;
const int BLOCK = 708;
struct dt{ int l,r,b,i; };
dt qr[MAXN];
int n,a[MAXN],cnt[MAXN],val[MAXN],ans[MAXN],bl[710],sum;

bool cmp(dt &q1,dt & q2){
	if(q1.l/BLOCK != q2.l/BLOCK){
		return q1.l < q2.l;
	}
	if((q1.l/BLOCK) & 1){
		return q1.r < q2.r;
	}
	return q1.r > q2.r;
}
void Add(int x)
{
    cnt[a[x]]++;
    if(cnt[a[x]]==1){sum++,bl[a[x]/BLOCK]++;}
    if(cnt[a[x]]==2){sum--,bl[a[x]/BLOCK]--;}
}
void Remove(int x)
{
    cnt[a[x]]--;
    if(cnt[a[x]]==1){sum++,bl[a[x]/BLOCK]++;}
    if(cnt[a[x]]==0){sum--,bl[a[x]/BLOCK]--;}
}
int solve()
{
    if(sum==0)return 0;

    for(int i=0; i<BLOCK; i++){
        if(bl[i]>0){
            for(int j=i*BLOCK; ; j++){
                if(cnt[j]==1){
                    return j;
                }
            }
        }
    }

    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&a[i]);

    int q; scanf("%d",&q);
    for(int i=0; i<q; i++){
        int l,r; scanf("%d%d",&l,&r);
        l--; r--;
        qr[i].l = l;
        qr[i].r = r;
        qr[i].b = l/BLOCK;
        qr[i].i = i;
    }

    sort(qr,qr+q,cmp);

    int l=0,r=-1;
    for(int i=0; i<q; i++)
    {
        while(r<qr[i].r) Add(++r);
        while(r>qr[i].r) Remove(r--);
        while(l>qr[i].l) Add(--l);
        while(l<qr[i].l) Remove(l++);
        ans[qr[i].i] = solve();
    }

    for(int i=0; i<q; i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}
