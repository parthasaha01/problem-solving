#include<bits/stdc++.h>
using namespace std;
map< pair < pair <int,int>, int >, int>mp;
int n,a[105],ans;

int main()
{
    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }



        sort(a+1,a+n+1);

        mp.clear();
        ans=0;

        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                for(int k=j+1; k<=n; k++)
                {
                    int x,y,z;
                    x=a[i];
                    y=a[j];
                    z=a[k];
                    if(mp[make_pair(make_pair(x,y),z)]==0)
                    {
                        if(x+y>z)
                        {
                            ans++;
                        }
                    }
                    mp[make_pair(make_pair(x,y),z)]=1;
                }
            }

        }

        printf("Case #%d: %d\n",ks,ans);

    }

    return 0;
}
