#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PLL pair<ll,ll>
string a,b;
PLL dp[10][2][2][2];
bool vis[10][2][2][2];

PLL fun(int pos, int choto, int boro, int suru) {
    if(pos<0) return make_pair(0LL, 1LL);
	 
    PLL &ret = dp[pos][choto][boro][suru];
    if(vis[pos][choto][boro][suru] && choto && boro) return ret;
    vis[pos][choto][boro][suru] = true;
    ret.first = ret.second = 0;

    int lo = 0, hi = 9;
    if(choto==0) hi = b[pos]-'0';
    if(boro==0)  lo = a[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        PLL temp = fun(pos-1, choto | (i<hi), boro | (i>lo), suru | (i>0));
        
        if(i==0 && suru)  ret.first += temp.second;
        
		ret.first += temp.first;
        ret.second += temp.second;
    }
	
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(vis, false, sizeof(vis));

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++) {
        cin>>a>>b;
        int flag = 0;
        if(a=="0") flag = 1;
        if(a.size()<b.size()) {
            int d = b.size() - a.size();
            string temp;
            while(d--) {
                temp += '0';
            }
            a = temp + a;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
		int n = b.size();
        PLL ans = fun(n-1,0,0,0);

        cout<<"Case "<<ks<<": "<<ans.first+flag<<endl;
    }

    return 0;
}

