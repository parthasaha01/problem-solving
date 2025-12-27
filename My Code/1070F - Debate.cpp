#include<bits/stdc++.h>
using namespace std;
vector<int>v[4];
bool cmp(int x, int y){
    return x>y;
}
int solve(){
    sort(v[0].begin(), v[0].end(), cmp);
    sort(v[1].begin(), v[1].end(), cmp);
    sort(v[2].begin(), v[2].end(), cmp);
    sort(v[3].begin(), v[3].end(), cmp);

    int v0 = (int)v[0].size();
    int v1 = (int)v[1].size();
    int v2 = (int)v[2].size();
    int v3 = (int)v[3].size();

    int c0=-1, c1=-1, c2=-1, c3=-1;
    int mn = min(v1,v2);
    int ans = 0;

    for(int i=0; i<mn; i++){
        ans += v[1][i];
        ans += v[2][i];
        c1++, c2++;
    }

    for(int i=0; i<v3; i++){
        ans += v[3][i];
        c3++;
    }

    vector<int>u;
    for(int i=c0+1; i<v0; i++){
        u.push_back(v[0][i]);
    }
    for(int i=c1+1; i<v1; i++){
        u.push_back(v[1][i]);
    }
    for(int i=c2+1; i<v2; i++){
        u.push_back(v[2][i]);
    }

    sort(u.begin(), u.end(), cmp);
    for(int i=0; i<v3 && i<u.size(); i++){
        ans += u[i];
        c3++;
    }

    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string s; int c;
        cin>>s>>c;
        if(s=="00"){
            v[0].push_back(c);
        }else if(s=="01"){
            v[1].push_back(c);
        }else if(s=="10"){
            v[2].push_back(c);
        }else{
            v[3].push_back(c);
        }
    }

    cout << solve() << endl;

    return 0;
}
