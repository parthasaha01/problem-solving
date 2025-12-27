#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int a[MAX+5],b[MAX+5];
int main()
{
    int n,k,x;
    while(scanf("%d%d%d",&n,&k,&x)==3)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        if(k==0){
            for(int i=1; i<=n; i++)b[i]=a[i];
        }
        else{
                for(int i=1; i<=n; i++){
                    if((a[i]^x)>a[i]){
                        b[i] = a[i]^x;
                    }
                    else{
                        b[i] = a[i];
                    }
                }
        }

        int mn = 1000000000;
        int mx = 0;
        for(int i=1; i<=n; i++){
            mn = min(mn,b[i]);
            mx = max(mx,b[i]);
        }

        printf("%d %d\n",mx,mn);
    }
    return 0;
}
