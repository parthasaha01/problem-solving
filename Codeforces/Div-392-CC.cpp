#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,m,k,x,y;

    while(cin>>n>>m>>k>>x>>y)
    {
        int mx,mn,sr;

        if(k<=n*m)
        {
            mx = 1;
            if(k==n*m) mn = 1;
            else mn = 0;

            ll dx,dy;
            if(k%m==0)dx = (k/m);
            else dx = (k/m)+1;
            dy = k%m;

            if(x>dx) sr = mn;
            else if(x<dx) sr = mx;
            else{
                if(y<=dy)sr = mx;
                else sr = mn;
            }

            cout << mx << " " << mn << " " << sr << endl;
            continue;
        }
        else
        {
            ll cnt = 0;
            ll d = k-(n*m);
            ll each = (n*m)-m;

            if(d%each<m)
            {
                int suru = d/each;
                if(d%each==0){
                    if(suru%2==1){
                        mx = suru+1;
                        mn = suru-2;
                        if(x==n)sr = mn;
                        else sr = mn;
                    }
                    else{
                        mx = suru+1;
                        mn = suru-1;
                        if(x==1||x==n)sr = mn;
                        else sr = mx;
                    }
                }
                else{
                    if(suru%2==0){
                        mx = suru+2;
                        mn = suru;
                        ll dk = d%each;
                        if(x==n)sr = mn;
                        else if(x==1){
                            if(dx)
                        }
                    }
                }
            }
            else
            {

            }

        }
    }

    return 0;
}
