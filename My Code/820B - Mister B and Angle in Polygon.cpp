#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a; cin>>n>>a;
    //double total_angle = (n-2.0)*180.0;
    //double each_angle = total_angle/(double)n;
    double each_part = 180.0/(double)n;

    double minn = 10000000.0;
    int p;
    for(int k=n,i=1; k>=3; k--,i++){
        double theta = each_part*(double)i;
        if(fabs(theta-a)<minn){
            minn = fabs(theta-a);
            p = k;
        }
    }

    cout << 1  << " " << 2 << " " << p << endl;

    return 0;
}
