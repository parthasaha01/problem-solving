#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,k;

    while(cin>>n)
    {
        if(n<=2){
            cout << "-1" << endl;
            continue;
        }
        if(n%2==1){
            m=(n*n+1)/2;
            k=m-1;
        }
        else{
            m=(n*n+4)/4;
            k=m-2;
        }

        cout << m << " " << k << endl;
    }

    return 0;
}
