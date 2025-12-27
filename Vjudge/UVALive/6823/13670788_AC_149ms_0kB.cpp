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
#define pf printf
#define ff first
#define ss second
#define sz 100005
#define sq(x) x*x
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define dist(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int fr[10];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //FastIO;
    //main();
    int flag = 0;
    string st;
    while(cin>>st)
    {
        vector<string>vec;
        string ss;
        for(int i=0; i<st.size(); i++)
        {
            if(st[i]>='0' && st[i]<='9')
            {
                ss+=st[i];
            }
            else
            {
                if(ss.size()>0)
                    vec.pb(ss);
                ss.clear();
            }
        }
        if(ss.size()>0)
            vec.pb(ss);

        ll ans = 0;
        for(int i=0; i<vec.size(); i++)
        {
            fr[0]=fr[1]=fr[2]=fr[3]=0;
            int sum = 0;
            for(int j=0; j<vec[i].size(); j++)
            {
                sum+=vec[i][j]-'0';
                sum%=3;
                if(sum==0)ans++;
                ans+=fr[sum];
                fr[sum]++;
            }
        }

        cout << ans << endl;

    }
    return 0;
}




