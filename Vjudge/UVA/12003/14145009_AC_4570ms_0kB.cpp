/*
* Allah is Almighty.......
*
* Mehedi Hasan Angkur <thisisangkur@gmail.com>
* CSE 11th Batch,MBSTU
* uva,cf id mbstu_angkur..
*
* keep coding...
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D double
#define pb push_back
#define mpp make_pair
#define sf scanf
#define pf prllf
#define ff first
#define ss second
#define sz 3*100005
#define sq(x) x*x
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define dist(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll arr[sz];
vector<ll>vec[sz];
ll n,m,u;


int main()
{

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    FastIO;
    while(cin>>n>>m>>u)
    {
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        ll index = -1 ;
        ll blk = sqrt(n);
        for(int i=0; i<n; i++)
        {
            if( i%blk == 0)
            {
                index++;
            }
            vec[index].pb(arr[i]);
        }
        for(int i=0; i<=index; i++)
        {
            sort(vec[i].begin(),vec[i].end());
        }
        ll l,r,v,p;
        ll pl,pr;
       // cout<<"here "<<endl;
        for(int i=0; i<m; i++)
        {
            cin>>l>>r>>v>>p;
            l--;
            r--;
            p--;
            pl = l ;
            pr = r ;
            ll cnt = 0 ;
            //cout<<l<<" -- "<<r<<" "<<endl;
           while(l<r && l%blk!=0)
            {

                if(arr[l]<v)
                    cnt++;
                l++;
            }
           // cout<<"first "<<endl;
            while(l+blk<=r)
            {
                ll pos = l/blk;
                ll lo = 0;
                ll hi = vec[pos].size()-1;
                ll ans = -1;
                while(lo<=hi)
                {
                    ll mid = lo+hi;
                    mid = mid/2;
                    if(vec[pos][mid]>=v)
                    {
                        hi = mid-1;
                    }
                    else
                    {
                        ans = mid ;
                        lo = mid + 1;
                    }
                }
                ans++;
                //cout<<"here "<<ans<<endl;
                    cnt+=ans;
                    l+=blk;
            }
            //cout<<" done "<<endl;
            while(l<=r)
            {
                if(arr[l]<v)
                    cnt++;
                l++;
            }
            // cout<<"firstttt "<<endl;
            ll pos = p/blk;
            ll val = arr[p];
            arr[p] = (u*cnt)/(pr-pl+1);
            for(int k=0; k<vec[pos].size(); k++)
            {
                if(vec[pos][k]==val)
                {
                    vec[pos][k] = arr[p];
                    break;
                }
            }
            sort(vec[pos].begin(),vec[pos].end());

        }
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<endl;
        }
        //cout<<endl;
    }
    return 0;
}
