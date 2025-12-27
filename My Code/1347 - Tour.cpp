#include<bits/stdc++.h>
using namespace std;
const double inf = 1000000000000000000.0;
#define pdd pair<double,double>
vector< pair<double,double> > v;
int n,vs[1005][1005];
double dp[1005][1005];
double dist(int p1,int p2)
{
    double x1 = v[p1].first;
    double y1 = v[p1].second;
    double x2 = v[p2].first;
    double y2 = v[p2].second;
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double fun(int i,int j)
{
    if(i==n-1||j==n-1){
        if(i<n-1)return dist(i,n-1);
        if(j<n-1)return dist(j,n-1);
    }
    if(vs[i][j]!=0)return dp[i][j];
    vs[i][j] = 1;
    int k = max(i,j)+1;
    double ret = inf;
    ret = min(ret,dist(i,k)+fun(k,j));
    ret = min(ret,dist(j,k)+fun(i,k));
    return dp[i][j] = ret;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    while(cin>>n)
    {
        v.clear();
        for(int i=0; i<n; i++){
            double x,y; cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        memset(vs,0,sizeof(vs));
        double ans = fun(0,0);
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
