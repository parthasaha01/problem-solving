#include<bits/stdc++.h>
#define sz 100005
#define ll long long
using namespace std;
vector<int>graph[sz];
ll n,m,a,b;
ll deg[sz];

void clr()
{
    memset(deg,0,sizeof(deg));
    for(int i=0; i<sz; i++)
    {
        graph[i].clear();
    }
}
int main()
{
    while(scanf("%lld%lld%lld%lld",&n,&m,&a,&b)==4)
    {
        clr();
        ll x,y;
        for(int i=0; i<m; i++)
        {
            scanf("%lld%lld",&x,&y);
            deg[x]++;
            deg[y]++;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=1; i<=n; i++)
        {
            cout<<i<<" "<<deg[i]<<endl;
        }

    }
}
