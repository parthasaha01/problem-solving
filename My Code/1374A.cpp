#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int solve(int x, int y, int n){
    int d = n/x;
    int r = n%x;
    if(r == y) return n;
    if((d*x+y) > n)d--;
    int k = d*x+y;
    return k;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int t=1; t<=tt; t++){
        int  x, y, n; cin>>x>>y>>n;
        cout<<solve(x,y,n)<<endl;
    }
    return 0;
}

