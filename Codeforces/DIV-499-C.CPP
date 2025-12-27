#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int n;
double m,a[1005],b[1005];
double EPS = 0.0000000001;

int check(double x)
{
    double cur = m+x;
    double rx = x;

    for(int i=1; i<=n; i++){
        double d = cur/a[i];
        cur -= d;
        rx -= d;
        if(cur<m)return 0;
        if(rx<0.0)return 0;
        double e = cur/b[i+1];
        cur -= e;
        rx -= e;
        if(cur<m)return 0;
        if(rx<0.0)return 0;
    }

    if(cur<m)return 0;
    if(rx<0.0)return 0;

    return 1;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    b[n+1] = b[1];

    double lo=0.0, hi = 1000000000.0;

    //int pp = check(8.0);
    //cout<<pp<<endl;

    double ans = -1.0;
    for(int i=1; i<=5000; i++)
    {
        double md = (lo+hi)/2.0;
        if(check(md)){
            ans = md;
            hi = md;
        }
        else{
            lo = md;
        }
    }

    if(ans<0.0)cout<<-1<<endl;
    else cout<<fixed<<setprecision(10)<<ans<<endl;

    return 0;
}


