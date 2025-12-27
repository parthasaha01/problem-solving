#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

string s;
int n,posible;
set<int> st[2];
vi v;
vvi ans;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> s)
    {
         st[0].clear(); st[1].clear();
         n = s.size();

        for(int i = 0; i < n; i++)
            st[s[i] - '0'].insert(i+1);

        ans = vvi(); posible = 1;

        while(!st[0].empty())
        {
            int f = 0, pos = 0;
            v = vi();
            while(1)
            {
                auto it = st[f].upper_bound(pos);
                if(it == st[f].end()) break;
                else
                {
                    pos = *it; st[f].erase(it);
                    v.push_back(pos);
                }
                f ^= 1;
            }
            if(f==0){ posible = 0; break;}
            ans.push_back(v);
        }
        if(!st[1].empty()) posible = 0;

        if(posible==0) cout << -1 << '\n';
        else
        {
            cout << ans.size() << '\n';
            for(auto p : ans)
            {
                cout << p.size();
                for(int x : p)
                    cout << " " << x;
                cout << '\n';
            }
        }
    }
    return 0;
}
