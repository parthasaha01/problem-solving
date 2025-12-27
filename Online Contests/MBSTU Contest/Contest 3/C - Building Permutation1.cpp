#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 300005
ll a[mx],cnt[mx];
ll ase[mx],nai[mx];
bool vis[mx];
int main()
{
    ll n,sum,diff,k,as,na;
    while(scanf("%I64d",&n)==1)
    {
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));

        as=0;
        for(int i=0; i<n; i++)
        {
            scanf("%I64d",&a[i]);

            if(a[i]>=1 && a[i]<=n)
            {
                if(vis[a[i]]==true)
                {
                    cnt[a[i]]++;
                    ase[as++]=a[i];
                }

                vis[a[i]]=true;
            }
            else
            {
                ase[as++]=a[i];
            }
        }

        na=0;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==false)
            {
                nai[na++]=i;
            }
        }

        sort(ase,ase+as);

        sum=0;

        for(int i=0; i<na; i++)
        {
            sum += abs(nai[i]-ase[i]);
        }

        printf("%I64d\n",sum);
    }

    return 0;
}

