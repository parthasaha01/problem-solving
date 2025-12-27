#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    int even=0,odd=0;

    for(int i=1; i<=n; i++)
    {
        if(a[i]>=0){
            even+=a[i];
        }
        else{
            odd+=((-1)*a[i]);
        }
    }

    int ans = even+odd;
    printf("%d\n",ans);

    return 0;

}
