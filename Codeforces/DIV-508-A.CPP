#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,k,a[MAXN][28];
string s;
int fun()
{
    memset(a,0,sizeof(a));

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i>0)a[i][j] = a[i-1][j];
        }

        int c = s[i]-'A';
        a[i][c]++;
    }

    int minn = 10000000;
    for(int i=0; i<k; i++){
        minn = min(minn,a[n-1][i]);
    }

    int ans = k*minn;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    cin>>s;

    int ans = fun();

    cout << ans << endl;

    //main();
    return 0;
}
