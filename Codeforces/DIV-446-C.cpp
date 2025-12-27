#include<bits/stdc++.h>
using namespace std;
#define mx 2005
int n,a[mx+5];
int main()
{
     scanf("%d",&n);

     int g = 0;
     int one=0;

     for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        g = __gcd(g,a[i]);
        if(a[i]==1)one++;
     }

     //printf("gcd=%d\n",g);

     if(g>1){
        printf("-1\n");
        return 0;
     }

     if(one==n){
        printf("0\n");
        return 0;
     }

     if(one>0){
        printf("%d\n",n-one);
        return 0;
     }

     int minn = 10000000;
     for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int gg = __gcd(a[i],a[j]);
            if(gg==1){
                minn = min(minn,j-i);
            }
        }
     }

     int ans = n+minn-1;
     printf("%d\n",ans);

     return 0;
}
