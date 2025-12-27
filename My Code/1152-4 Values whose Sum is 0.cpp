#include<bits/stdc++.h>
using namespace std;
#define mx 4005
int a[mx],b[mx],c[mx],d[mx],s[mx*mx];
int binarySearchLB(int k, int v)
{
    int lo = 1,hi = k;
    int lb = -1;
    while(lo<=hi){
        int md = (lo+hi)/2;
        if(s[md]==v) lb = md, hi = md-1;
        else if(s[md]>v) hi = md-1;
        else lo = md+1;
    }
    return lb;
}
int binarySearchUB(int k, int v)
{
    int lo = 1,hi = k;
    int ub = -1;
    while(lo<=hi){
        int md = (lo+hi)/2;
        if(s[md]==v) ub = md,lo = md+1;
        else if(s[md]>v) hi = md-1;
        else lo = md+1;
    }
    return ub;
}
int main()
{
    int t; scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++)
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);

        int k = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                s[++k] = a[i] + b[j];

        sort(s+1,s+k+1);

        int cnt = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int v = c[i] + d[j];
                int lb = binarySearchLB(k,-v);
                if(lb!=-1){
                    int ub = binarySearchUB(k,-v);
                    cnt += ub-lb+1;
                }
            }
        }

        if(ks==1) printf("%d\n",cnt);
        else printf("\n%d\n",cnt);
    }
    return 0;
}
