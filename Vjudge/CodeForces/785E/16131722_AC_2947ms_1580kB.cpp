#include<bits/stdc++.h>
using namespace std;
#define mx 200000ll
#define ll long long
int n, sq, ar[mx+2], bu[mx+2];
ll ans=0;
void init() {
    sq=sqrt(n+.0)+1;
    for(int i=0; i<n; i++) bu[i] = ar[i];
    for(int i=0; i*sq<n; i++) {
        int l=i*sq; int r=min((i+1)*sq-1,n);
        sort(bu+l,bu+r+1);
    }
}
/// How many numbers are there from l to ri greater than v
int qug(int l,int r,int v) {
    int nl=l/sq, nr=r/sq; int res=0;
    if(nl==nr) {
        for(int i=l; i<=r; i++)if(ar[i]>v)res++;
        return res;
    }
    for(int i=l,j=(nl+1)*sq-1; i<=j; i++)if(ar[i]>v)res++;
    for(int i=nl+1; i<nr; i++) {
        int lo=i*sq; int hi=min((i+1)*sq-1,n); int sesh=hi;
        int ans=0;
        while(lo<=hi) {
            int mid=(lo+hi)/2;
            if(bu[mid]>v) {
                ans=(sesh-mid+1);
                hi=mid-1;
            } else lo=mid+1;
        }
        res+=ans;
    }
    for(int i=nr*sq; i<=r; i++)if(ar[i]>v)res++;
    return res;
}
/// How many numbers are there from l to ri less than v
int qul(int l,int r,int v) {
    int nl=l/sq, nr=r/sq; int res=0;
    if(nl==nr) {
        for(int i=l; i<=r; i++)if(ar[i]<v)res++;
        return res;
    }
    for(int i=l,j=(nl+1)*sq-1; i<=j; i++)if(ar[i]<v)res++;
    for(int i=nl+1; i<nr; i++) {
        int lo=i*sq; int hi=min((i+1)*sq-1,n); int suru=lo;
        int ans=0;
        while(lo<=hi) {
            int mid=(lo+hi)/2;
            if(bu[mid]<v) {
                ans=(mid-suru+1);
                lo=mid+1;
            } else hi=mid-1;
        }
        res+=ans;
    }
    for(int i=nr*sq; i<=r; i++)if(ar[i]<v)res++;
    return res;
}
void update(int in,int val){
    int s=in/sq; int l=s*sq; int r=min(n,(s+1)*sq-1);
    ar[in]=val;
    for(int i=l; i<=r; i++) bu[i]=ar[i];
    sort(bu+l,bu+r+1);
}
void  query(int x,int y) {
    if(x==y)return;
    ll sum = qul(x, y-1, ar[y]);
    sum -= qug(x, y-1, ar[y]);
    sum += qug(x+1, y, ar[x]);
    sum -= qul(x+1, y, ar[x]);

    if(ar[x]>ar[y]) sum++;
    else sum--;

    ans+=sum;
    swap(ar[x],ar[y]);
    update(x,ar[x]);
    update(y,ar[y]);
}
int main() {
    int q; scanf("%d%d",&n,&q);
    for(int i=0; i<n; i++)ar[i]=i;
    init();
    while(q--) {
        int x,y; scanf("%d%d",&x,&y); x--,y--;
        if(x>y)swap(x,y);
        query(x,y);
        printf("%lld\n",ans);
    }
    return 0;
}
