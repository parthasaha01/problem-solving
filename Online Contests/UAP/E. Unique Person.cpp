#include<bits/stdc++.h>
using namespace std;
int last[100005],a[100005];
map<int,int>mp;
set<int>ss;
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {

        int n; scanf("%d",&n);

        mp.clear();
        ss.clear();

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            ss.insert(a[i]);
        }

        set<int> :: iterator it;
        int k=0;
        for(it=ss.begin(); it!=ss.end(); it++)
        {
            mp[*it] = ++k;
        }

        memset(last,0,sizeof(last));
        int ans = 1;
        int b = 1;
        last[mp[a[1]]]=1;
        for(int e=2; e<=n; e++)
        {
            int ls = last[mp[a[e]]];
            if(ls>=b)b=ls+1;
            int cnt = (e-b)+1;
            ans = max(ans,cnt);
            last[mp[a[e]]] = e;
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
