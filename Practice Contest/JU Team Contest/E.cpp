#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>dv;
int main()
{
    ll nn,n,d;

    while(cin>>nn>>d)
    {
        ll mx = 0;
        ll bs = 2;

        if(nn<10)
        {
            if(nn==0 && d==0)
            {
                cout << "2" << " " << "1" << endl;
                continue;
            }
            for(ll x=2; x<=nn+1; x++)
            {
                ll cnt = 0;
                ll xx = nn;
                while(xx%x==d && xx>0)
                {
                    cnt++;
                    xx /= x;
                }

                if(cnt>mx)
                {
                    mx = cnt;
                    bs = x;
                }
            }

            cout << bs << " " << mx << endl;
            continue;
        }

        n=nn-d;
        ll sq = sqrt(n);
        for(ll  i=2; i<=sq; i++)
        {
            if(n%i==0)
            {
                if(i>d)dv.push_back(i);
                if((n/i)>d && (n/i)!=i)dv.push_back(n/i);
            }
        }


        if(n>d)dv.push_back(n);

        sort(dv.begin(),dv.end());
        ll sz = dv.size();

        for(ll k=sz-1; k>=0; k--)
        {
            ll x=dv[k];
            if(x<2)continue;
            ll cnt=0;
            ll xx=nn;
            while(xx>0 && xx%x==d)
            {
                cnt++;
                xx/=x;
            }
            if(cnt>=mx)
            {
                mx=cnt;
                bs = x;
            }
        }

        cout<<bs<<" "<<mx<<endl;

        dv.clear();
    }

    return 0;
}

// 100000000 3
