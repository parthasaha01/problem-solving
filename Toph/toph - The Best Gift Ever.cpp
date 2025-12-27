#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mx 100005
int a[mx],b[mx];
LL sa[mx],sb[mx];
int main()
{
    int T; scanf("%d",&T);
    for(int ks=1; ks<=T; ks++){
        printf("Case %d:\n",ks);
        int N,M; scanf("%d%d",&N,&M);
        for(int i=1; i<=N; i++) scanf("%d",&a[i]);
        for(int i=1; i<=M; i++) scanf("%d",&b[i]);
        sa[0] = sb[0] = 0;
        for(int i=1; i<=N; i++) sa[i] = sa[i-1] + a[i];
        for(int i=1; i<=M; i++) sb[i] = sb[i-1] + b[i];

        int Q; scanf("%d",&Q);
        for(int q=1; q<=Q; q++){
            int i,j,k,l; scanf("%d%d%d%d",&i,&j,&k,&l);
            LL ra = sa[j] - sa[i-1];
            LL rb = sb[l] - sb[k-1];
            LL ans = ra*rb;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
