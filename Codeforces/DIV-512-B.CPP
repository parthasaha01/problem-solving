#include<bits/stdc++.h>
using namespace std;
double EPS = 0.0000001;
double area;
double x1,y1,x2,y2,x3,y3,x4,y4;
double get_area(double x1, double y1, double x2, double y2, double x3, double y3){
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
int solve(double x, double y){
    double A1 = get_area(x, y, x1, y1, x2, y2);
    double A2 = get_area(x, y, x2, y2, x3, y3);
    double A3 = get_area(x, y, x3, y3, x4, y4);
    double A4 = get_area(x, y, x1, y1, x4, y4);
    double tot = A1 + A2 + A3 + A4;
    double diff = fabs(area-tot);
    if(diff<EPS)return 1;
    else return 0;
}
int main(){
    double n,d;
    cin>>n>>d;

    x1 = 0;
    y1 = d;

    x2 = n-d;
    y2 = n;

    x3 = n;
    y3 = n-d;

    x4 = d;
    y4 = 0;

    double A1 = get_area(x1,y1,x2,y2,x3,y3);
    double A2 = get_area(x3,y3,x4,y4,x1,y1);
    area = A1+A2;

    int m; cin>>m;
    while(m--){
        double x,y;
        cin>>x>>y;
        int f = solve(x,y);
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
