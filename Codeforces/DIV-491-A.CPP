#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005

int main()
{
    //ios :: sync_with_stdio(false); cin.tie(0);
    int a,b,c,n;
    while(cin>>a>>b>>c>>n)
    {
        int aub;
        aub = a+b-c;
        int ans = n-aub;

        if(n<=a||n<=b||n<=c){
            cout << -1 << endl;
        }
        else if(aub<a||aub<b||aub<c)
        {
            cout << -1 << endl;
        }
        else if(ans<1){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }

    return 0;

}
