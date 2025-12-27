#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c,d;

    while(cin>>a>>b>>c>>d)
    {
        if(b>d){
            swap(b,d);
            swap(a,c);
        }

        ll ss=b;
        ll tt=d;

        if(ss==tt){
            cout << ss << endl;
            continue;
        }

        ll sum = -1;
        ll x = a;
        ll y = c;


        while(1)
        {
            //cout << ss << " " << tt << " " << x << " " << y << endl;

            if(ss==tt){
                sum = ss;
                break;
            }

            if(ss>tt && x>=y && a>=c){
                break;
            }
            if(tt>ss && y>=x && c>=a){
                break;
            }

            ss = b+x;
            tt = d+y;
            x+=a;
            y+=c;
        }

        cout << sum << endl;
    }
    return 0;
}
