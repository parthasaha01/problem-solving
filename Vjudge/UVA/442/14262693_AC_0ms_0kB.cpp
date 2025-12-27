#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
map<char, pair<ll,ll> >mp;
int n;
string s;
ll fun()
{
    if(s.size()==1)return 0;
    stack< pair<ll,ll> > mat;
    stack<char>st;

    ll ans = 0;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            pll q = mat.top();
            mat.pop();
            pll p = mat.top();
            mat.pop();
            if(p.second!=q.first)return -1;
            ans += (p.first*p.second*q.second);
            mat.push(make_pair(p.first,q.second));
            st.pop();
        }
        else{
            mat.push(mp[s[i]]);
        }
    }
    return ans;
}
int main()
{
    ios :: sync_with_stdio(false); cin.tie(0);
    while(cin>>n)
    {
        mp.clear();

        for(int i=1; i<=n; i++){
            char mat; ll row,col;
            cin>>mat>>row>>col;
            mp[mat] = make_pair(row,col);
        }

        while(cin>>s)
        {
            ll ans = fun();
            if(ans==-1){
                cout << "error" << endl;
            }
            else{
                cout << ans << endl;
            }
        }
    }
    
    return 0;
}
