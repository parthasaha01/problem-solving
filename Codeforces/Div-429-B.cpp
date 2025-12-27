#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,tot,a[1000005],sum[1000005];
int main()
{
    while(scanf("%I64d",&n)==1)
    {
        //sum[0]=0;
        tot=0;
        bool odd=false;
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
            //sum[i]=sum[i-1]+a[i];
            tot+=a[i];
            if(a[i]%2==1)odd=true;
        }

        if(tot%2==1)
        {
            printf("First\n");
        }
        else
        {
            if(odd==false)
            {
                printf("Second\n");

            }
            else
            {
                printf("First\n");
            }
        }
    }

    return 0;
}
