#include<bits/stdc++.h>
using namespace std;
#define mx 10000000
#define ll long long int
bool flag[mx+2];
string ss;
int n;
void sieve()
{
    flag[0]=1;
    flag[1]=1;
    flag[2]=0;
    for(ll i=4; i<=mx; i+=2)flag[i]=1;

    ll sq = sqrt(mx);
    for(ll i=3; i<=sq; i+=2)
    {
        if(flag[i]==0)
        {
            for(ll j=i*i; j<=mx; j+=i+i)
            {
                flag[j]=1;
            }
        }
    }
}

vector<string> vec;
map<string,int>Map;
ll to_int(string s)
{
    ll r = 0;
    istringstream SIN(s);
    SIN >> r;
    return r;
}
void fun(int pos, string str)
{
    if(pos==n)
    {
        sort(str.begin(), str.end());
        if(Map[str]<=0) vec.push_back(str);
        Map[str]++;
        return;
    }
    fun(pos+1, str+ss[pos]);
    fun(pos+1, str);
}

int main()
{
    sieve();

    int tt;
    scanf("%d",&tt);

    while(tt--)
    {
        cin >> ss;
        n = ss.size();
//        cout << "n = " << n << endl;
        Map.clear();
        vec.clear();

        sort(ss.begin(),ss.end());
        fun(0,"");

        ll ans = 0;

        for(int i=0; i<vec.size(); i++)
        {
            string sr = vec[i];

            do
            {
                ll cnt = to_int(sr);

                if(flag[cnt]==0 && sr[0]!='0')
                {
                    //cout << sr << " " << cnt << endl;
                    ans++;
                }
            }
            while(next_permutation(sr.begin(),sr.end()));
        }

        printf("%lld\n",ans);
    }
    return 0;
}

