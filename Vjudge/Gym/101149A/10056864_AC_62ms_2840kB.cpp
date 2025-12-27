#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        int maxx = -100000000;
        for(int i=1; i<=n; i++)maxx = max(maxx,a[i]);

        printf("%d\n",maxx);
    }
    return 0;
}