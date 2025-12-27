#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[5];
int main()
{
    ll n,x;

    while(cin>>n>>x)
    {
        ll r = n%6;

        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[x]= 1;

        for(ll i=r; i>=1; i--)
        {
            if(i&1)
            {
                swap(a[0],a[1]);
            }
            else
            {
                swap(a[1],a[2]);
            }
        }

        if(a[0])printf("0\n");
        else if(a[1])printf("1\n");
        else printf("2\n");
    }

    return 0;
}
