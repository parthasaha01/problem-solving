#include<bits/stdc++.h>
using namespace std;
vector<int>st,ed;
int n,p;
int startSearch(int x)
{
    int lo=0,hi=n-1,cnt=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(st[md]<=x){
            cnt = md+1;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }
    return cnt;
}
int endSearch(int x)
{
    int lo=0,hi=n-1,cnt=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(ed[md]<x){
            cnt = md+1;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }
    return cnt;
}
int check(int x)
{
    for(int i=0; i<n; i++){
        int u = startSearch(st[i]);
        int v = endSearch(st[i]-x);
        if(u-v>=p)return 1;
    }
    return 0;
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&p);
        st.clear(); ed.clear();
        for(int i=1; i<=n; i++){
            int s,e; scanf("%d%d",&s,&e);
            st.push_back(s);
            ed.push_back(e);
        }

        sort(st.begin(),st.end());
        sort(ed.begin(),ed.end());

        int lo=0,hi=1000000000,ans;
        while(lo<=hi)
        {
            int md = (lo+hi)/2;
            if(check(md)){
                ans = md;
                hi = md-1;
            }
            else{
                lo = md+1;
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
