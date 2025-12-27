#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);
        mp.clear();
        int maxx=0;

        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            mp[x]++;
            if(mp[x]>maxx){
                maxx=mp[x];
            }
        }

        printf("Case %d: %d\n",ks,maxx);
    }

    return 0;
}
