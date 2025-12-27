#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int a[100],b[100],fr[100];
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        //if(fr[a[i]]==0)fr[a[i]]++;
    }

    for(int i=1; i<=m; i++)
    {
        scanf("%d",&b[i]);
        //if(fr[b[i]]<2)fr[b[i]]++;
    }

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                printf("%d\n",a[i]);
                return 0;
            }
        }
    }


    int x1 = a[1];
    int x2 = b[1];

    if(x1>x2)swap(x1,x2);

    printf("%d%d\n",x1,x2);

    return 0;
}
