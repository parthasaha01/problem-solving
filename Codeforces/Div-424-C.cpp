#include<bits/stdc++.h>
using namespace std;
int n,k,d,a[2005],b[2005],c[2005];
map<int,int>mp,mx,ms;
bool check(int x)
{
    ms.clear();
    for(int i=1; i<=k; i++)
    {
        int v = x+c[i];
        ms[v] = 1;
    }

    for(int j=1; j<=n; j++)
    {
        if(ms[b[j]]==0)return false;
    }

    return true;

}
int main()
{
    scanf("%d%d",&k,&n);

    for(int i=1; i<=k; i++)scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)scanf("%d",&b[i]);

    for(int i=1; i<=k; i++)c[i]=c[i-1]+a[i];
    for(int i=1; i<=n; i++)mp[b[i]]=1;

    int ans=0;
    d = k-n;

    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=k; i++)
        {
            int x = b[j]-c[i];
            if(mx[x]==1)continue;
            mx[x]=1;
            if(check(x))ans++;

        }
    }

    printf("%d\n",ans);

    return 0;
}
