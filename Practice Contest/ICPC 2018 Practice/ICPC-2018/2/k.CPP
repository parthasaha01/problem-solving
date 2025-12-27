#include<bits/stdc++.h>
using namespace std;
int a[105];
vector<int>v;
int main()
{
    freopen("cubes.in","r",stdin);
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int n; scanf("%d",&n);
        v.clear();

        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        if(n&1){
            int m = (1+n)/2;
            int k = -1;
            a[m] = v[++k];
            for(int i=1; i+m<=n; i++){
                a[m-i] = v[++k];
                a[m+i] = v[++k];
            }
        }
        else{
            int m = (1+n)/2;
            int k = -1;
            a[m] = v[++k];
            for(int i=1; i+m<n; i++){
                a[m+i] = v[++k];
                a[m-i] = v[++k];
            }
            a[n] = v[n-1];
        }

        printf("Case %d:\n",ks);
        for(int i=1; i<=n; i++){
            if(i==n)printf("%d\n",a[i]);
            else printf("%d ",a[i]);
        }
    }
    return 0;
}
