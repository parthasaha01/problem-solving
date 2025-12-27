#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int ans = 0;
        for(int i=0;i<5;i++)
        {
            int a;
            scanf("%d",&a);
            if(a==n)
                ans++;
        }
        printf("%d\n",ans);
    }
}
