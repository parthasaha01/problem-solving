#include<bits/stdc++.h>
using namespace std;
int a[2005],n;
vector<int>v;
int BinarySearch(int x)
{
    int lo=1;
    int hi=n;
    int ans=0;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(a[md]<=x){ans=md; lo=md+1;}
        else hi = md-1;
    }
    return n-ans;
}
int main()
{
    while(scanf("%d",&n))
    {
        if(!n)break;

        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);

        v.clear();
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                int x = a[i]+a[j];
                v.push_back(x);
            }
        }

        //sort(v.begin(),v.end());
        int ans=0;
        for(int i=0; i<v.size(); i++){
            ans+=BinarySearch(v[i]);
        }

        printf("%d\n",ans);
    }

    return 0;
}
