#include<bits/stdc++.h>
using namespace std;
int a[1005];
double p[1005];
int main(){
    int tt; scanf("%d",&tt);
    while(tt--){
        int n,e; scanf("%d%d",&n,&e);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        sort(a,a+n);
        if(e<a[0] || e>a[n-1]){
            printf("-1\n");
        }else{
            if(n==1){
                printf("%.10f\n",1.0);
            }else{
                if(a[0]==a[n-1]){
                    printf("%.10f ",1.0);
                    for(int i=1; i<n; i++){
                        if(i==n-1)printf("0\n");
                        else printf("0 ");
                    }
                }else if(a[n-1]==e){
                    for(int i=0; i<n-1; i++) printf("0 ");
                    printf("%.10f\n",1.0);
                }else if(a[0]==e){
                    printf("%.10f ",1.0);
                    for(int i=1; i<n; i++){
                        if(i==n-1)printf("0\n");
                        else printf("0 ");
                    }
                }else{
                    p[0] = (double)(a[n-1] - e) / (double)(a[n-1]-a[0]);
                    p[n-1] = 1.0 - p[0];
                    printf("%.10f ",p[0]);
                    for(int i=1; i<n-1; i++)printf("0 ");
                    printf("%.10f\n",p[n-1]);
                }
            }
        }
    }
    return 0;
}
