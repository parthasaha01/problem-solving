#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,a[mx+5];
map<int,int>mp,sp;
int main()
{
    while(scanf("%d",&n)==1)
    {
        mp.clear();
        sp.clear();

        int sum=0;
        mp[0]=1;
        sp[1]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            mp[sum]=i+1;
            sp[i+1]=sum;
        }

        if(sum%3!=0){
            printf("0\n");
            continue;
        }

        int each = sum/3;
        int ans=0;

        for(int i=1; i<=n-2; i++)
        {
            int x = i;
            int xp = sp[x];
            int dd = xp+each;
            if(mp[dd]==0)continue;

            int y = mp[dd];
            if(y>n || y<=x)continue;

            int yp = sp[y];
            int ee = yp+each;
            if(mp[ee]==0)continue;

            int z = mp[ee];
            if(z>n || z<=y)continue;

            ans++;
        }

        printf("%d\n",ans);
    }
    return 0;
}
