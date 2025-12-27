#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;

    if(k==0){
        cout << "1 1" << endl;
    }
    else if(k==((n*m)-1LL)){
        cout << "1 2" << endl;
    }
    else{
        ll br = n+m-2;
        ll row=1,col=2;
        if(k<=br){
            if(k<n){
                col = 1;
                row = k+1;
            }
            else{
                row = n;
                col = (k-n)+2;
            }

            cout << row << " " << col << endl;
        }
        else{
            ll v = k-br;
            ll cnt = v/(m-1);
            if(v%(m-1)!=0)cnt++;
            row = n-cnt;

            ll nn,mm;
            nn = n-1;
            mm = m-1;
            ll x = nn-row;
            ll u = x*mm;
            ll r = v-u;

            if(row%2==0){
                col = r+1;
            }
            else{
                col = (m-r)+1;
            }

            cout << row << " " << col << endl;
        }
    }

    //main();

    return 0;
}
