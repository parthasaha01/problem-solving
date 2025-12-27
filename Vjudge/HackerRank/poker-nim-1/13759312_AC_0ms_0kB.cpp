#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n, k;
        scanf("%d %d",&n,&k);

        long long sum = 0;
        for(int i=1; i<=n; i++){
            long long x;
            scanf("%lld",&x);
            sum ^= x;
        }

        if(sum>0){
            printf("First\n");
        }
        else{
            printf("Second\n");
        }
    }

    return 0;
}
