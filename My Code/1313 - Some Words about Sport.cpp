#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[10005];
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&a[i][j]);
        }
    }

    int xth = 0;

    for(int k=1; k<=n; k++)
    {
        for(int i=k,j=1; j<=k; j++,i--)
        {
            b[++xth] = a[i][j];
        }
    }

    for(int k=2; k<=n; k++)
    {
        for(int i=n,j=k; j<=n; j++,i--)
        {
            b[++xth] = a[i][j];
        }
    }

    for(int i=1; i<=xth; i++)
    {
        if(i<xth)printf("%d ",b[i]);
        else printf("%d\n",b[i]);
    }
    return 0;
}

