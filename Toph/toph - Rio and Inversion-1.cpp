#include<bits/stdc++.h>
using namespace std;
#define N tree[node]
#define L tree[lson]
#define R tree[rson]
int a[10005],ans = 0;
vector<int>tree[4*10005];
struct data{
    int t,x,y;
};
vector<data>qr;
void build(int node, int b, int e){
    if(b==e){
        tree[node].push_back(a[b]);
        return;
    }
    int lson=(node<<1), rson=lson+1, m=(b+e)/2;
    build(lson,b,m);
    build(rson,m+1,e);
    merge(L.begin(),L.end(),R.begin(),R.end(),back_inserter(N));
}
int query(int node,int b,int e,int x,int y,int v,int c){
    if(x>y)return 0;
    if(b==x && e==y){
        if(c==0){
            int cnt = lower_bound(N.begin(),N.end(),v)-N.begin();
            return cnt;
        }else{
            int cnt = upper_bound(N.begin(),N.end(),v)-N.begin();
            return (e-b+1)-cnt;
        }
    }
    int lson=(node<<1), rson=lson+1, m=(b+e)/2;
    if(y<=m) return query(lson,b,m,x,y,v,c);
    else if(x>m) return query(rson,m+1,e,x,y,v,c);
    else return query(lson,b,m,x,m,v,c) + query(rson,m+1,e,m+1,y,v,c);
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    build(1,1,n);

    ans = 0;
    for(int i=1; i<=n; i++){
        ans += query(1,1,n,i+1,n,a[i],0);
    }

    //int q; scanf("%d",&q);
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            data xx;
            xx.t = 0, xx.x=i, xx.y=j;
            qr.push_back(xx);
            xx.t = 1, xx.x=i, xx.y=j;
            qr.push_back(xx);
        }
	}
    for(int i=0; i<qr.size(); i++){
        int type; //scanf("%d",&type);
        type = qr[i].t;
        if(type==0){
            int x,y; //scanf("%d%d",&x,&y);
            x = qr[i].x; y = qr[i].y;
            if(x>y)swap(x,y);
            x++, y++;
            int res = ans;
            if(a[x]!=a[y]){
                res -= query(1,1,n,x+1,n,a[x],0);
                res -= query(1,1,n,1,x-1,a[x],1);
                res -= query(1,1,n,y+1,n,a[y],0);
                res -= query(1,1,n,1,y-1,a[y],1);
                if(a[x]>a[y])res++;

                res += query(1,1,n,x+1,n,a[y],0);
                res += query(1,1,n,1,x-1,a[y],1);
                res += query(1,1,n,y+1,n,a[x],0);
                res += query(1,1,n,1,y-1,a[x],1);
                if(a[x]<a[y])res++;
            }
            printf("%d %d %d = %d\n",type,--x,--y,res);
        }else{
            int x,y; //scanf("%d%d",&x,&y);
            x = qr[i].x; y = qr[i].y;
            if(x>y)swap(x,y);
            x++, y++;
            int res = ans;
            for(int i=x; i<=y; i++){
                res -= query(1,1,n,y+1,n,a[i],0);
                res -= query(1,1,n,1,x-1,a[i],1);
                res -= query(1,1,n,i+1,y,a[i],0);
            }
            printf("%d %d %d = %d\n",type,--x,--y,res);
        }
    }
    return 0;
}

