#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 300005
ll a[mx],cnt[mx];
bool vis[mx];
int main()
{
    ll n,sum,diff,k;
    while(scanf("%I64d",&n)==1)
    {
        memset(cnt,0,sizeof(cnt));
        memset(vis,false,sizeof(vis));

        for(int i=0; i<n; i++)
        {
            scanf("%I64d",&a[i]);

            if(a[i]>=1 && a[i]<=n)
            {
                if(vis[a[i]]==true)
                    cnt[a[i]]++;
                vis[a[i]]=true;
            }
        }
        sort(a,a+n);
        sum=0;
        k=0;
        for(int v=1; v<=n && k<n;)
        {
            if(vis[v]==false)
            {
                if(a[k]<1 || a[k]>n)
                {
                    diff = abs(v-a[k]);
                    sum += diff;
                    k++;
                    vis[v]=true;
                    v++;
                }
                else
                {
                    if(cnt[a[k]]!=0)
                    {
                        diff = abs(v-a[k]);
                        sum += diff;
                        k++;
                        vis[v]=true;
                        v++;
                        cnt[a[k]]--;
                    }
                    else
                    {
                        k++;
                    }
                }

            }
            else
            {
                v++;
            }

        }

        printf("%I64d\n",sum);
    }

    return 0;
}
