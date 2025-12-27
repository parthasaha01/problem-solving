#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n,m,k;

    while(cin>>n>>m>>k)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }

        int min1=999999999;
        int min2=999999999;

        int cnt=0;
        for(int i=m+1; i<=n; i++){
            cnt+=10;
            if(a[i]<=k && a[i]!=0){
                min1=cnt;
                break;
            }
        }

        cnt=0;
        for(int i=m-1; i>=1; i--){
            cnt+=10;
            if(a[i]<=k && a[i]!=0){
                min2=cnt;
                break;
            }
        }

        int ans = min(min1,min2);

        printf("%d\n",ans);
    }

    return 0;
}
