#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
vector<int>vv;
int n, k;
int fun(int x)
{
    int lo=0;
    int hi = n-1;
    int cnt = 0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(vv[md]<=x){
            cnt = md+1;
            lo = md+1;
        }
        else{
            hi = md-1;
        }

    }

    return cnt;
}
int main()
{
    cin>>n>>k;

    for(int i=0; i<n; i++)
    {
        int x; scanf("%d",&x);
        vv.push_back(x);
    }

    sort(vv.begin(),vv.end());

    int lo=1;
    int hi=1000000000;
    int ans = -1;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int v = fun(md);

        if(v==k){
            ans = md;
            break;
        }
        else if(v<k)
        {
            lo = md+1;
        }
        else
        {
            hi = md-1;
        }
    }

    cout << ans << endl;

    vv.clear();

    //main();

    return 0;
}

