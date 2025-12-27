/*
* Allah is Almighty.......
* File Name: D - Tri graphs .cpp
* Mehedi Hasan Angkur <thisisangkur@gmail.com>
* CSE 11th Batch,MBSTU
* uva,cf id mbstu_angkur..
* Date: 2017-07-29
* keep coding...
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D double
#define pb push_back
#define mp make_pair
#define sf scanf
#define pf printf
#define ff first
#define ss second
#define sz 100005
#define sq(x) x*x
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define dist(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll arr[sz][5];
ll dp[sz][5];
ll n;

ll fun(ll i, ll j) {
   // getchar();
    if (i > n || j > 3 || i < 1 || j < 1)
        return INT_MAX;
    
    if (i == n && j == 2)
        return arr[i][j];
    
    if(i==n && j==3)
    return INT_MAX;
    
    if (dp[i][j] != INT_MIN)
        return dp[i][j];
    
    ll ret = INT_MAX;
    
    if (j == 1) 
    {
        ret = min(ret,arr[i][j] + fun(i + 1, j));
        ret = min(ret,arr[i][j] + fun(i + 1, j + 1));
        ret = min(ret,arr[i][j] + fun(i, j + 1));
    }
     else if (j == 2) 
     {

        ret = min(ret,arr[i][j] + fun(i + 1, j - 1));
        ret = min(ret,arr[i][j] + fun(i + 1, j));
        ret = min(ret,arr[i][j] + fun(i + 1, j + 1));
        ret = min(ret,arr[i][j] + fun(i, j + 1));
    } 
    else if (j == 3) {
        ret = min(ret,arr[i][j] + fun(i + 1, j - 1));
        ret = min(ret,arr[i][j] + fun(i + 1, j));
        
    }
    
    return dp[i][j] = ret;
}
int main() {

int cas = 1 ;
    while (sf("%lld", &n) == 1 && n) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= 3; j++) {
                sf("%lld", &arr[i][j]);
                dp[i][j] = INT_MIN;
            }
        }
        
        pf("%d. %lld\n",cas++,fun(1,2));
        //cout << fun(1, 2) << endl;

    }

    return 0;
}




