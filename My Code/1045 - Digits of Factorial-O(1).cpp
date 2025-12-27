#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main()
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++)
    {
        int n, base;
        scanf("%d %d",&n,&base);
        int ans=1;
        if(n!=0)
            ans=ceil((n*log(n)-n+0.5*log(2*n*pi))/log(base));   //stirling formula
        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}
