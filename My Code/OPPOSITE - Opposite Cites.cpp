#include<bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int solve(int n){
    if(n&1)return -1;
    int half = n/2;
    for(int i=1; i<=half; i++){
        if(a[i]!=-1 && a[i+half]!=-1){
            if(a[i]!=a[i+half])return -1;
            b[i] = b[i+half] = a[i];
        }else if(a[i]!=-1 && a[i+half]==-1){
            b[i] = b[i+half] = a[i];
        }else if(a[i]==-1 && a[i+half]!=-1){
            b[i] = b[i+half] = a[i+half];
        }else{
            b[i] = b[i+half] = 1;
        }
    }
    return 1;
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int n; scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        int flag = solve(n);

        if(flag==-1){
            printf("NO\n");
        }else{
            printf("YES\n");
            for(int i=1; i<=n; i++){
                if(i<n)printf("%d ",b[i]);
                else printf("%d\n",b[i]);
            }
        }
    }
    return 0;
}
