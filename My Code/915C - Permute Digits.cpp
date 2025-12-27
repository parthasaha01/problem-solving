#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
string a,b;
int n;
map< int, map<vi,ll> > mp;
bool cmp(int x,int y){
    return x>y;
}
ll fun(int choto, vi v) {

    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++)
}
int main() {
    cin>>a>>b;
    n = a.size();
    vector<int>v(n);
    for(int i=0; i<n; i++)v[i]=a[i]-'0';
    ll ans = fun(0,v);
}
