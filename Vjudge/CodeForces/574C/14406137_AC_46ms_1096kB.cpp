#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 40000
int n,a[100005],b[100005];
int normalize(int m)
{
    while(m%2==0)m/=2;
    while(m%3==0)m/=3;
    return m;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];

    for(int i=1; i<=n; i++){
        int x = normalize(a[i]);
        b[i] = x;
    }

    int ans = 1;

    for(int i=1; i<n; i++){
        if(b[i]!=b[i+1]){
            ans = 0; break;
        }
    }

    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

