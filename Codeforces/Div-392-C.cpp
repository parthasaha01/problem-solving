#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,m,k,x,y;

    while(cin>>n>>m>>k>>x>>y)
    {
        ll each = n*m;
        ll cnt = 0;

        ll suru = k/each;

        int mx,mn,sr;

        if(k%each==0)
        {
            cout << suru << " " << suru << " " << suru << endl;
        }
        else
        {
            mx = suru+1;
            mn = suru;

            if(suru%2==0)
            {
                ll soman = suru*n*m;
                ll d = k-soman;

                ll dx,dy;
                if(d%m==0)
                {
                    dx = (d/m);
                    dy = m;
                }
                else
                {
                    dx = (d/m)+1;
                    dy = d%m;
                }

                if(x>dx){
                    sr = mn;
                }
                else if(x<dx){
                    sr = mx;
                }
                else{
                    if(y<=dy)sr = mx;
                    else sr = mn;
                }

            }
            else
            {
                ll soman = suru*n*m;
                ll d = k-soman;

                ll dx,dy;

                if(d%m==0)
                {
                    dx = n-(d/m)+1;
                    dy = m;
                }
                else
                {
                    dx = n-(d/m);
                    dy = d%m;
                }

                if(x==dx)
                {
                    if(y<=dy)sr = mx;
                    else sr = mn;
                }
                else if(x<dx){
                    sr = mn;
                }
                else{
                    sr = mx;
                }

            }

            cout << mx << " " << mn << " " << sr << endl;
        }


    }

    return 0;
}
