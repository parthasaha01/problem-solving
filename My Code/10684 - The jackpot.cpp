#include<bits/stdc++.h>
using namespace std;
int a[10005],s[10005];
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        s[0]=0;
        for(int i=1; i<=n; i++){
            s[i] = s[i-1]+a[i];
            if(s[i]<0)s[i]=0;
        }

        int ans=0;

        for(int i=1; i<=n; i++){
            ans = max(ans,s[i]);
        }

        if(ans==0){
            printf("Losing streak.\n");
        }
        else{
            printf("The maximum winning streak is %d.\n",ans);
        }
    }
    return 0;
}
