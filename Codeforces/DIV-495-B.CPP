#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int n,m,lf[1005],rg[1005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>n>>m;

    for(int i=1; i<=m; i++){
        cin>>lf[i]>>rg[i];
    }

    string ans;
    int d = 1;
    for(int i=1; i<=n; i++){
        ans += d+'0';
        d = 1-d;
    }

    cout << ans << endl;

    return 0;
}
