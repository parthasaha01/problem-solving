#include<bits/stdc++.h>
using namespace std;
vector<int>v,a;
int n,m;
bool check(int x)
{
    int lo=0;
    int hi=a.size()-1;

    while(lo<=hi)
    {
        int md=(lo+hi)/2;

        if(a[md]==x)return true;
        if(a[md]<x)lo=md+1;
        else hi=md-1;
    }
    return false;
}
int UpperBound(int x)
{
    int lo=0;
    int hi=v.size()-1;
    int ans=0;
    while(lo<=hi)
    {
        int md=(lo+hi)/2;

        if(v[md]==x)return v[md];
        if(v[md]<x){ans=v[md]; lo=md+1;}
        else hi=md-1;
    }

    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            a.push_back(i);
            if(i!=(n/i))a.push_back(n/i);
        }
    }

    sort(a.begin(),a.end());

    for(int i=1; i*i<=m; i++){
        if(m%i==0){
            if(check(i))v.push_back(i);
            if(i!=(m/i) && check(m/i))v.push_back(m/i);
        }
    }

    sort(v.begin(),v.end());

    int q; scanf("%d",&q);

    for(int k=1; k<=q; k++)
    {
        int low,high; scanf("%d%d",&low,&high);
        if(low>high)swap(low,high);

        int ans = UpperBound(high);
        if(ans<low)printf("-1\n");
        else printf("%d\n",ans);
    }

    return 0;
}
