#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int a[100005];
int main(){
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    int q; scanf("%d",&q);

    while(q--){
        int k; scanf("%d",&k);
        v.clear();
        for(int i=1; i<=n; i++){
            if(a[i]%k==0){
                v.push_back(a[i]/k);
            }
        }

        int gcd = 0;
        for(int i=0; i<v.size(); i++){
            gcd = __gcd(gcd,v[i]);
        }

        if(gcd==1){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
    }

    return 0;
}
