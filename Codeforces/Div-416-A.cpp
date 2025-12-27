#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b;

    while(cin>>a>>b)
    {
        ll na = sqrt(a);

        ll nb = (na*na)+na;

        //ll sb = (na*(4+((na-1)*2)))/2;

        //cout <<

        if(b<nb)cout << "Valera" << endl;
        else cout << "Vladik" << endl;
    }
    return 0;
}
