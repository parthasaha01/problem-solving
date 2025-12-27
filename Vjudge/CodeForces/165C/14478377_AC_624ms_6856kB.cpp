#include<bits/stdc++.h>
using namespace std;
int k,n,cum[1000005];
string s;
int fun(int i,int v)
{
    int lo=i, hi = n;
    int l=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(cum[md]==v){
            l = md;
            hi=md-1;
        }
        else if(cum[md]<v){
            lo=md+1;
        }
        else{
            hi=md-1;
        }
    }
    if(l==0)return 0;

    lo=i, hi=n;
    int r=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(cum[md]==v){
            r = md;
            lo=md+1;
        }
        else if(cum[md]<v){
            lo=md+1;
        }
        else{
            hi=md-1;
        }
    }
    if(r==0)return 0;
    return r-l+1;
}
int main()
{
    cin>>k>>s;
    n = s.size();
    s = "0"+s;

    for(int i=1; i<=n; i++){
        cum[i] = cum[i-1]+(s[i]-'0');
    }

    long long ans = 0;
    for(int i=1; i<=n; i++){
        ans += fun(i,cum[i-1]+k);
    }

    cout << ans << endl;

    return 0;
}
