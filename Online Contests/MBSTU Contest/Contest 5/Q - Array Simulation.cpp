#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[105],b[105],d;
int main()
{
    int t,n,m,x,y;
    char ch;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d%d",&n,&m);

        for(int i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
        }

        for(int k=0; k<m; k++)
        {

            getchar();
            scanf("%c",&ch);
            if(ch=='S')
            {
                scanf("%lld",&d);
                for(int i=0; i<n; i++)
                {
                    a[i] += d;
                }
            }
            else if(ch=='M')
            {
                scanf("%lld",&d);
                for(int i=0; i<n; i++)
                {
                    a[i] *= d;
                }
            }
            else if(ch=='D')
            {
                scanf("%lld",&d);
                for(int i=0; i<n; i++)
                {
                    a[i] /= d;
                }
            }
            else if(ch=='R')
            {
                for(int i=0; i<n; i++)
                {
                    b[i]=a[i];
                }
                for(int i=0; i<n; i++)
                {
                    a[i]=b[n-i-1];
                }
            }
            else if(ch=='P')
            {
                scanf("%d%d",&x,&y);
                swap(a[x],a[y]);
            }
        }

        printf("Case %d:\n",kase);

        for(int i=0; i<n; i++){
            if(i==n-1)
                printf("%lld",a[i]);
            else
                printf("%lld ",a[i]);
        }
        printf("\n");
    }

    return 0;
}
