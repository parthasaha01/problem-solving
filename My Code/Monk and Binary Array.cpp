#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        int ans = 0;

        for(int k=1; k<=n; k++)
        {
            a[k]=1-a[k];
            int cnt=0;

            for(int i=1; i<=n; i++)
            {
                int sum=0;
                for(int j=i; j<=n; j++)
                {
                    sum+=a[j];
                    if(sum%2==1)
                    {
                        cnt++;
                    }

                }
            }

            ans = max(ans, cnt);

            a[k]=1-a[k];
        }

        printf("%d\n",ans);
    }
    return 0;
}
