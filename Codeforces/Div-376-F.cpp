#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[200005];
bool vis[200005];
ll calculate(int n)
{
    ll ans=0LL;
    ll com=999999999999;

    for(int i=0; i<n; i++)
    {
        int p=a[i];
        ll sum=0LL;
        bool flag=true;
        if(i!=0&&com<a[i-1]){
            break;
        }
        if(vis[p]==false)
        {
            sum+=p;
            com=0;
            for(int j=i+1; j<n; j++)
            {
                if(a[j]%p==0)
                {
                    sum+=a[j];
                    vis[a[j]]=true;
                    flag=false;
                }
                else
                {
                    sum+=a[j]-(a[j]%p);
                    com+=(a[j]%p);
                }
            }
            ans=max(ans,sum);
            if(flag){
                false;
            }
        }
        vis[p]=true;
    }

    return ans;
}
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        memset(vis,false,sizeof(vis));

        ll ans=calculate(n);

        printf("%I64d\n",ans);
    }

    return 0;
}
