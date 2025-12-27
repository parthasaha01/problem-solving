#include<bits/stdc++.h>
using namespace std;
#define N tree[node]
#define L tree[lson]
#define R tree[rson]
struct data{ int t,x,y; };
int dp[10005][10005],a[10005];
int n,INV,ans=0;
vector<int>tree[4*10005];
vector<data>qr;
vector<int>pp,qq;
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
void solve1(){
    for(int i=1;i<=n;i++){
		dp[i][n+1]=dp[i-1][n+1];
		for(int j=1;j<i;j++) if(a[i]<a[j]) dp[i][n+1]++;
	}
	for(int i=n;i;i--){
		dp[0][i]=dp[0][i+1];
		for(int j=i+1;j<=n;j++) if(a[i]>a[j]) dp[0][i]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=n;j>i;j--){
			dp[i][j]=dp[i-1][j]+dp[i][j+1]-dp[i-1][j+1];
			if(a[j]<a[i]) dp[i][j]++;
		}
	INV = dp[n][n+1];
}
void solve2(){
    build(1,1,n);

    ans = 0;
    for(int i=1; i<=n; i++){
        ans += query(1,1,n,i+1,n,a[i],0);
    }
}
int get_res1(int typ, int l, int r){
    l++, r++;
    if(r<l) swap(l,r);
    int res = INV;
    if(!typ){
        for(int p=l+1;p<r;p++){
            if(a[l] > a[p]) res--;
            if(a[l] < a[p]) res++;
            if(a[r] > a[p]) res++;
            if(a[r] < a[p]) res--;
        }
        if(a[r] > a[l]) res++;
        if(a[l] > a[r]) res--;
    }else res=dp[l-1][r+1];
    return res;
}
int get_res2(int type, int x, int y){
    if(type==0){
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
        return res;

    }else{
        if(x>y)swap(x,y);
        x++, y++;
        int res = ans;
        for(int i=x; i<=y; i++){
            res -= query(1,1,n,y+1,n,a[i],0);
            res -= query(1,1,n,1,x-1,a[i],1);
            res -= query(1,1,n,i+1,y,a[i],0);
        }
        return res;
    }
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);

	solve1();
	solve2();

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
		int type,l,r; //scanf("%d%d%d",&typ,&l,&r); l++,r++;
		type = qr[i].t, l = qr[i].x, r = qr[i].y;
		int res = get_res1(type,l,r);
		pp.push_back(res);
		int ret = get_res2(type,l,r);
		qq.push_back(ret);
	}

	for(int i=0; i<qr.size(); i++){
        int type,l,r; //scanf("%d%d%d",&typ,&l,&r); l++,r++;
		type = qr[i].t, l = qr[i].x, r = qr[i].y;
		if(pp[i]!=qq[i]){
            printf("pp->%d %d %d = %d\n",type,l,r,pp[i]);
            printf("qq->%d %d %d = %d\n\n",type,l,r,qq[i]);
		}
	}

	return 0;
}
/*
25
3 8 2 5 12 1 7 14 9 5 3 8 4 4 3 5 5 4 1 1 10 1 7 7 9
12
3 8 2 5 12 1 7 14 9 5 3 8


*/

