#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx+5];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        sort(a+1,a+n+1);

        bool flag=false;
        for(int i=1; i<=n-2; i++){
            if(a[i]+a[i+1]>a[i+2]){
                if(a[i]+a[i+2]>a[i+1]){
                    if(a[i+1]+a[i+2]>a[i]){
                        flag = true;
                        break;
                    }
                }
            }
        }

        if(flag)printf("YES\n");
        else printf("NO\n");

    }

    return 0;
}
