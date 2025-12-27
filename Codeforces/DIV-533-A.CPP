#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int n,a[1005];
int fun(int t){
    int cost = 0;
    for(int i=1; i<=n; i++){
        int cnt = abs(a[i]-t);
        if(cnt>1){
            int c1 = abs(a[i]-t);
            int c2 = abs(a[i]-(t-1));
            int c3 = abs(a[i]-(t+1));
            int mn = min(c1,min(c2,c3));
            cost += mn;
        }
    }
    return cost;
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    int tt = 1000000, ret = 1000000000;
    for(int t=1; t<=10000; t++){
        int cost = fun(t);
        if(cost<ret){
            tt = t;
            ret = cost;
        }
    }

    cout<<tt<<" "<<ret<<endl;

    return 0;
}
