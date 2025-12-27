#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>dv[1000005],RR[100005];
int L[100005],R[100005],a[100005];
int last[1000005],tree[400005];
struct dt{
    int x,y,id,v;
}qr[100005];
bool cmp1(dt p,dt q){
    if(p.y==q.y)return p.x<q.x;
    return p.y<q.y;
}
bool cmp2(dt p,dt q){
    return p.id<q.id;
}
void divisor()
{
//    for(int n=1; n<=1000000; n++){
//        int sq = sqrt(n);
//        for(int i=1; i<=sq; i++){
//            if(n%i==0){
//                dv[n].push_back(i);
//                if(i!=(n/i))dv[n].push_back(n/i);
//            }
//        }
//        sort(dv[n].begin(),dv[n].end());
//    }

    for(int i=1; i<=1000000; i++){
        for(int v=i; v<=1000000; v+=i){
            dv[v].push_back(i);
        }
    }
}
void update(int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){ tree[nd]+=v; return; }
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);
    tree[nd] = tree[lf]+tree[rg];
}
int query(int nd,int b,int e,int x,int y)
{
    if(b>y||e<x)return 0;
    if(b>=x&&e<=y)return tree[nd];
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    return query(lf,b,md,x,y) + query(rg,md+1,e,x,y);
}
int main()
{
    divisor();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,q; scanf("%d%d",&n,&q);

        for(int i=1; i<=n; i++) scanf("%d",&a[i]);

        for(int i=1; i<=1000000; i++)last[i]=0;

        for(int i=1; i<=n; i++){
            int pos = 0;
            for(int j=0; j<dv[a[i]].size(); j++){
                pos = max(pos,last[dv[a[i]][j]]);
            }
            L[i] = pos+1;
            last[a[i]]=i;
        }

        for(int i=1; i<=1000000; i++)last[i]=n+1;
        for(int i=1; i<=100001; i++)RR[i].clear();

        for(int i=n; i>=1; i--){
            int pos = n+1;
            for(int j=0; j<dv[a[i]].size(); j++){
                pos = min(pos,last[dv[a[i]][j]]);
            }
            R[i] = pos-1;
            last[a[i]]=i;
            RR[pos].push_back(i);
        }

        for(int i=1; i<=q; i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            if(x>y)swap(x,y);
            qr[i].x = x;
            qr[i].y = y;
            qr[i].id = i;
        }

        sort(qr+1,qr+q+1,cmp1);
        memset(tree,0,sizeof(tree));
        int k=1;
        
        for(int i=1; i<=n; i++)
        {
            update(1,1,n,i,+1);
            if(L[i]-1>0) update(1,1,n,L[i]-1,-1);
            for(int j=0; j<RR[i].size(); j++)
            {
                int x = RR[i][j];
                update(1,1,n,x,-1);
                if(L[x]-1>0)update(1,1,n,L[x]-1,+1);
            }

            while(k<=q)
            {
                if(qr[k].y>i)break;
                qr[k].v = query(1,1,n,qr[k].x,qr[k].y);
                k++;
            }
        }

        sort(qr+1,qr+q+1,cmp2);

        printf("Case %d:\n",ks);
        for(int i=1; i<=q; i++)printf("%d\n",qr[i].v);
    }
    return 0;
}
