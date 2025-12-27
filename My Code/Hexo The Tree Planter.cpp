#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        bool flag=1;
        int ls,v;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            {
                if(flag&&a[i])
                {
                    ls=i;
                    v=a[i];
                    flag=0;
                }
            }
        }

        int zero=1;

        if(flag){
            printf("Case %d: %d\n",ks,n);   // all a[i] is zero
            continue;
        }
        int maxx=0;
        for(int i=ls+1; i<=n; i++)
        {
            int u=a[i];

            if(u!=0)
            {
                if(u==v)
                {
                    ls=i;
                }
                else
                {
                    int d=i-zero;   //d=(i-1)-zero+1
                    maxx=max(maxx,d);
                    zero=ls+1;
                    ls=i;
                    v=u;
                }
            }
        }

        int d=n-zero+1;
        maxx=max(maxx,d);

        printf("Case %d: %d\n",ks,maxx);
    }

    return 0;
}

