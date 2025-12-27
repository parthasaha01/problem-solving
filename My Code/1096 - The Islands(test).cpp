#include<bits/stdc++.h>
using namespace std;
#define pdd pair<double,double>
const double inf = 1000000000000000000.0;
const double EPS = 1e-12;
vector< pair<double,double> > v;
vector<int>LR,RL;
int n,b1,b2,vs[101][101][3][3];
double dp[101][101][3][3];
void PRINT(vector<int>p,vector<int>q,double cost)
{
    cout << "Cost = " << fixed << setprecision(2) << cost << " -> ";
    for(int i=0; i<p.size(); i++){
            cout << p[i] << " ";
    }
    cout << " ... ";
    for(int i=0; i<q.size(); i++){
        if(i==q.size()-1)cout << q[i] << endl;
        else cout << q[i] << " ";
    }
    cout << endl;
}
double dist(int p1,int p2)
{
    double x1 = v[p1].first;
    double y1 = v[p1].second;
    double x2 = v[p2].first;
    double y2 = v[p2].second;
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double fun(int i,int j,int f1,int f2,double cost,vector<int>p,vector<int>q)
{
    if(i==n-1||j==n-1){
        if(i<n-1){
            p.push_back(n-1);
            cost += dist(i,n-1);
            if(q[q.size()-1]==n-1)q.pop_back();
            reverse(q.begin(),q.end());
            PRINT(p,q,cost);
            return dist(i,n-1);
        }
        if(j<n-1){
            cost += dist(j,n-1);
            if(q[q.size()-1]==n-1)q.pop_back();
            reverse(q.begin(),q.end());
            PRINT(p,q,cost);
            return dist(j,n-1);
        }
    }
    //if(vs[i][j][f1][f2]!=0)return dp[i][j][f1][f2];
    vs[i][j][f1][f2] = 1;

    double ret = inf;
    int k = max(i,j)+1;

    if(i==0&&j==0&&k==1)
    {
        if(k==b1){
            p.push_back(k);
            ret = min(ret,dist(i,k)+fun(k,j,1,f2,cost+dist(i,k),p,q));
            p.pop_back();
        }
        else if(k==b2){
            p.push_back(k);
            ret = min(ret,dist(i,k)+fun(k,j,f1,1,cost+dist(i,k),p,q));
            p.pop_back();
        }
        else{
            p.push_back(k);
            ret = min(ret,dist(i,k)+fun(k,j,f1,f2,cost+dist(i,k),p,q));
            p.pop_back();
        }
    }
    else if(k==b1)
    {
        if(f2==0)
        {
            p.push_back(k);
            ret = min(ret,dist(i,k)+fun(k,j,1,f2,cost+dist(i,k),p,q));
            p.pop_back();
            q.push_back(k);
            ret = min(ret,dist(j,k)+fun(i,k,2,f2,cost+dist(j,k),p,q));
            q.pop_back();
        }
        else if(f2==1)
        {
            q.push_back(k);
            ret = min(ret,dist(j,k)+fun(i,k,2,f2,cost+dist(j,k),p,q));
            q.pop_back();
        }
        else /// f2==2
        {
            p.push_back(k);
            ret = min(ret,dist(i,k)+fun(k,j,1,f2,cost+dist(i,k),p,q));
            p.pop_back();
        }
    }
    else if(k==b2)
    {
        if(f1==0)
        {
            p.push_back(k);
            ret = min(ret,dist(i,k)+fun(k,j,f1,1,cost+dist(i,k),p,q));
            p.pop_back();
            q.push_back(k);
            ret = min(ret,dist(j,k)+fun(i,k,f1,2,cost+dist(j,k),p,q));
            q.pop_back();
        }
        else if(f1==1)
        {
            q.push_back(k);
            ret = min(ret,dist(j,k)+fun(i,k,f1,2,cost+dist(j,k),p,q));
            q.pop_back();
        }
        else /// f1==2
        {
            p.push_back(k);
            ret = min(ret,dist(i,k)+fun(k,j,f1,1,cost+dist(i,k),p,q));
            p.pop_back();
        }
    }
    else
    {
        p.push_back(k);
        ret = min(ret,dist(i,k)+fun(k,j,f1,f2,cost+dist(i,k),p,q));
        p.pop_back();
        q.push_back(k);
        ret = min(ret,dist(j,k)+fun(i,k,f1,f2,cost+dist(j,k),p,q));
        q.pop_back();
    }
    return dp[i][j][f1][f2] = ret;
}
//void path(int i,int j,int f1,int f2)
//{
//    if(i==n-1||j==n-1){
//        if(i<n-1){
//            LR.push_back(n-1);
//            return;
//        }
//        if(j<n-1){
//            RL.push_back(n-1);
//            return;
//        }
//    }
//
//    double ret = fun(i,j,f1,f2);
//    int k = max(i,j)+1;
//
//    if(i==0&&j==0){
//        if(k==b1){
//            double ret1 = dist(i,k)+fun(k,j,1,b2);
//            if(fabs(ret-ret1)<EPS){
//                LR.push_back(k);
//                path(k,j,1,b2);
//            }
//        }
//        else if(k==b2){
//            double ret1 = dist(i,k)+fun(k,j,b1,1);
//            if(fabs(ret-ret1)<EPS){
//                LR.push_back(k);
//                path(k,j,b1,1);
//            }
//        }
//        else{
//            double ret1 = dist(i,k)+fun(k,j,b1,b2);
//            if(fabs(ret-ret1)<EPS){
//                LR.push_back(k);
//                path(k,j,b1,b2);
//            }
//        }
//    }
//    else if(k==b1)
//    {
//        if(b2==0)
//        {
//            double ret1 = dist(i,k)+fun(k,j,1,b2);
//            double ret2 = dist(j,k)+fun(i,k,2,b2);
//            if(fabs(ret-ret1)<EPS){
//                LR.push_back(k);
//                path(k,j,1,b2);
//            }
//            else{
//                RL.push_back(k);
//                path(i,k,2,b2);
//            }
//        }
//        else if(b2==1)
//        {
//            double ret1 = dist(j,k)+fun(i,k,2,b2);
//            if(fabs(ret-ret1)<EPS){
//                RL.push_back(k);
//                path(i,k,2,b2);
//            }
//        }
//        else /// b2==2
//        {
//            double ret1 = dist(i,k)+fun(k,j,1,b2);
//            if(fabs(ret-ret1)<EPS){
//                LR.push_back(k);
//                path(k,j,1,b2);
//            }
//        }
//    }
//    else if(k==b2)
//    {
//        if(b1==0)
//        {
//            double ret1 = dist(i,k)+fun(k,j,b1,1);
//            double ret2 = dist(j,k)+fun(i,k,b1,2);
//            if(fabs(ret-ret1)<EPS){
//                LR.push_back(k);
//                path(k,j,b1,1);
//            }
//            else{
//                RL.push_back(k);
//                path(i,k,b1,2);
//            }
//        }
//        else if(b1==1)
//        {
//            double ret1 = dist(j,k)+fun(i,k,b1,2);
//            if(fabs(ret-ret1)<EPS){
//                RL.push_back(k);
//                path(i,k,b1,2);
//            }
//        }
//        else /// b1==2
//        {
//            double ret1 = dist(i,k)+fun(k,j,b1,1);
//            if(fabs(ret-ret1)<EPS){
//                LR.push_back(k);
//                path(k,j,b1,1);
//            }
//        }
//    }
//    else
//    {
//        double ret1 = dist(i,k)+fun(k,j,f1,f2);
//        double ret2 = dist(j,k)+fun(i,k,f1,f2);
//        if(fabs(ret-ret1)<EPS){
//            LR.push_back(k);
//            path(k,j,f1,f2);
//        }
//        else{
//            RL.push_back(k);
//            path(i,k,f1,f2);
//        }
//    }
//
//}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int ks = 0;
    while(cin>>n>>b1>>b2)
    {
        if(!n&&!b1&&!b2)break;

        v.clear();
        LR.clear();
        RL.clear();

        if(b1>b2)swap(b1,b2);

        for(int i=0; i<n; i++){
            double x,y; cin>>x>>y;
            v.push_back(make_pair(x,y));
        }

        memset(vs,0,sizeof(vs));
        vector<int>p,q;
        p.push_back(0);
        q.push_back(0);
        double ans = fun(0,0,0,0,0.0,p,q);
        LR.push_back(0);
        RL.push_back(0);
        //path(0,0,0,0);
        RL.pop_back();
        reverse(RL.begin(),RL.end());
        cout << "Case " << ++ks << ": " << fixed << setprecision(2) << ans << endl;
        for(int i=0; i<LR.size(); i++){
            cout << LR[i] << " ";
        }
        for(int i=0; i<RL.size(); i++){
            if(i==RL.size()-1)cout << RL[i] << endl;
            else cout << RL[i] << " ";
        }
    }
    return 0;
}

