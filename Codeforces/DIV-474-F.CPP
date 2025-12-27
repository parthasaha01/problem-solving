#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int n,m,s[100005],a[100005],L[100005];
struct dt
{
    int u,v,w,t;
} st[100005];
vector<int>ed[100005];
vector<int>cs[100005];
int binarySearch(int v)
{
    int lo=0; int hi=n; int ans;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(s[md]<v){
            ans=md;
            lo=md+1;
        }
        else{
            hi = md-1;
        }
    }
    return ans+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ed[u].push_back(v);
        cs[u].push_back(w);
        st[i].u = u;
        st[i].v = v;
        st[i].w = w;
        st[i].t = i;
        a[i] = w;
    }

    //sort(st+1,st+m+1,cmp);

    s[0] = -inf;
    for(int i=1; i<=n; i++)s[i]=inf;

    int lis = 0;

    for(int i=1; i<=n; i++)
    {
        int v = a[i];
        int p = binarySearch(v);
        s[p] = v;
        L[i] = p;
        lis = max(lis,p);
    }


}
