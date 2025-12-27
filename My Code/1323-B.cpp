#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
int a[40005], b[40005], cuma[40005], cumb[40005];
vector< pair<int, int> >divisor;
void get_divisor(int k) {
    for(int i=1; i*i<=k; i++) {
        if(k%i==0) {
            divisor.push_back(make_pair(i, k/i));
            if(i != (k/i)){
                divisor.push_back(make_pair(k/i, i));
            }
        }
    }
}

ll calc(int x, int y, int n, int m) {
    ll xb = 0;
    for(int i=x; i<=m; i++){
        if(cumb[i]-cumb[i-x] == x){
            xb++;
        }
    }
    ll ya = 0;
    for(int i=y; i<=n; i++){
        if(cuma[i]-cuma[i-y] == y) {
            ya++;
        }
    }
    return xb*ya;
}
ll fun(int n,int m,int k) {
    if(k==1) {
        return cuma[n]*cumb[m];
    }

    divisor.clear();
    get_divisor(k);

    ll ans = 0;
    for(int i=0; i<divisor.size(); i++) {
        int x = divisor[i].first;
        int y = divisor[i].second;
        ans += calc(x,y,n,m);
    }
    return ans;
}
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        cuma[i] = cuma[i-1] + a[i];
    }
    for(int i=1; i<=m; i++){
        scanf("%d",&b[i]);
        cumb[i] = cumb[i-1] + b[i];
    }

    ll ans = fun(n,m,k);

    printf("%lld\n",ans);

    return 0;
}
