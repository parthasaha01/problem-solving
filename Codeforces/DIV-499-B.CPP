#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int n,m,cnt[105],a[105];
vector<int>v;
bool cmp(int x,int y){
    return x>y;
}
int check(int x)
{
    int k = v.size();
    int cc = 0;
    for(int i=0; i<k; i++){
        int u = v[i];
        int d = u/x;
        cc+=d;
        if(cc>=n)return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    if(n>m){
        cout<<0<<endl;
        return 0;
    }

    for(int i=1; i<=100; i++){
        if(cnt[i]>0){
            v.push_back(cnt[i]);
        }
    }

    sort(v.begin(),v.end(),cmp);

    int lo=1, hi = 100;
    int ans = 0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(check(md)){
            ans = md;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }

    cout<<ans<<endl;

    return 0;
}

