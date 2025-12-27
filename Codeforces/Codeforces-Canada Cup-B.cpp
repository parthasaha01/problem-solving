#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll func(char ch)
{
    if(ch=='f') return 1;
    if(ch=='e') return 2;
    if(ch=='d') return 3;
    if(ch=='a') return 4;
    if(ch=='b') return 5;
    if(ch=='c') return 6;
}
int main()
{
    ll n;
    char ch;

    while(cin>>n>>ch)
    {
        ll r=n%4;
        ll ans=0;
        ll c=func(ch);

        if(r==0)
        {
            ll time=n/2;
            ll p=(time-1)*6;
            ans = p+c+(n-3);

        }
        else if(r==1)
        {
            ll time=(n+1)/2;
            ll p=(time-1)*6;
            ans = p+c+(n-1);;
        }
        else if(r==2)
        {
            ll time=(n+2)/2;
            ll p=(time-1)*6;
            ans = p+c+(n-1);;
        }
        else
        {
            ll time=(n-1)/2;
            ll p=(time-1)*6;
            ans = p+c+(n-3);
        }

        cout << ans << endl;
    }

    return 0;
}
