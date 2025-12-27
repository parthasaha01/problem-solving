#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 3162280
bool vis[mx+5];
ll n,sz;
vector<ll>pr;
void sieve()
{
    pr.push_back(2);
    for(ll i=3; i<=mx; i+=2)
    {
        if(vis[i]==false)
        {
            pr.push_back(i);

            for(ll j=i*i; j<=mx; j+=i+i)
            {
                vis[j]=true;
            }
        }
    }

    sz = pr.size();
}
int main()
{
    sieve();
    cin>>n;
    ll v=n;
    bool flag = false;
    ll u=0;
    for(ll i=0; i<sz && pr[i]*pr[i]<=n; i++)
    {
        if(n%pr[i]==0)
        {
            if(flag==true && u*pr[i]!=n)
            {
                cout << "1" << endl;
                cout << u*pr[i] << endl;

                //main();
                return 0;
            }

            u=pr[i];
            flag=true;
        }

        ll x = pr[i]*pr[i];
        if(n%x==0 && n!=x)
        {
            cout << "1" << endl;
            cout << x << endl;

            //main();

            return 0;
        }
    }

    if(flag==false)
    {
        cout << "1" << endl;
        cout << "0" << endl;
    }
    else
    {
        cout << "2" << endl;
    }

    //main();

    return 0;
}
