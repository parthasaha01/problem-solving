#include<bits/stdc++.h>
using namespace std;
int n,x,ase,cnt,a[105];
int main()
{
    scanf("%d%d",&n,&x);
    ase=0;
    cnt=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<x)cnt++;
        if(a[i]==x)ase++;
    }

    int ans = x-cnt;
    ans += ase;

    printf("%d\n",ans);

    return 0;
}
