#include<bits/stdc++.h>
using namespace std;
#define mx 100000
#define ll long long
bool vis[mx+5];
vector<int>pr;
vector< pair<int,int> edge;
void sieve(int n,int m)
{
    //pr.push_back(2);
    for(int i=2; i<=mx; i++){
        if(vis[i]==false){
            pr.push_back(i);
            for(int j=i+i; j<=mx; j+=i){
                vis[j]=true;
            }
        }
    }

    //int n = pr.size();
    //printf("%d %d\n",n,pr[n-1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n,m; cin>>n>>m;
    sieve(n,m);

    if(((n*(n-1))/2)<m){
        cout << "impossible" << endl;
        return 0;
    }

    cout << "possible" << endl;

}
