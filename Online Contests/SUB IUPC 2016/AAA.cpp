#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;

    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        int ans = max(a,max(b,c));
        printf("%d\n",ans);
    }
    return 0;
}
