#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int fr[10];
int main()
{
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
