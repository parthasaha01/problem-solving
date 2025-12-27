#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[10][10];
int fun(int p, int q, int a[][10])
{
    //printf("p=%d\n",p);
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            printf("%d ",a[i][j]);
//        }
//        printf("\n\n");
//    }

   // getchar();

    if(p==n && q==m)
    {
        for(int i=0; i<n; i++){
            int cnt = 1;
            for(int j=0; j<m; j++){
                cnt*=a[i][j];
            }
            if(cnt!=k)return 0;
        }
        for(int j=0; j<m; j++){
            int cnt = 1;
            for(int i=0; i<n; i++){
                cnt*=a[i][j];
            }
            if(cnt!=k)return 0;
        }

        return 1;

    }

    int ret = 0;

    if(q==m-1){
        a[p][q]=1;
        int nq=0;
        if(p==n-1)nq=q+1;
        ret += fun(p+1,nq,a);
        a[p][q]=-1;
        ret += fun(p+1,nq,a);
    }
    else{
        a[p][q]=1;
        ret += fun(p,q+1,a);
        a[p][q]=-1;
        ret += fun(p,q+1,a);
    }

    return ret;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        int ans = fun(0,0,b);
        printf("ans=%d\n",ans);
    }

    return 0;
}
//#include <stdio.h>
//#define ll long long
//const int mod=1e9+7;
//int pow(int x, ll p)
//{
//	int ret=1;
//	for(;p;p>>=1,x=(ll)x*x%mod) if(p&1) ret=(ll)ret*x%mod;
//	return ret;
//}
//int main()
//{
//	ll n,m,k;
//	scanf("%lld %lld %lld",&n,&m,&k);
//	int sol=pow(2,n-1);
//	sol=pow(sol,m-1);
//	if(k==-1 && n%2!=m%2) printf("0\n");
//	else printf("%i\n",sol);
//	return 0;
//}
