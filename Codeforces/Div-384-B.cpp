#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int a[mx+5];
int main()
{
    ll n,k;
    while(cin>>n>>k)
    {
        ll cnt = 1;
        while(k%2==0)
        {
            k/=2;
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}

