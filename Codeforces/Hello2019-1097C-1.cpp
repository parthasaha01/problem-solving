#include<bits/stdc++.h>
using namespace std;
vector<string>a;
vector<int>v;
vector<int>openning;
set<int>cl[500005];
int fun(int id){
    stack<char>x;
    for(int i=0; i<a[id].size(); i++){
        if(a[id][i]=='('){
            x.push(a[id][i]);
        }else{
            if(!x.empty()){
                x.pop();
            }else{
                return 2;
            }
        }
    }

    if(!x.empty()){
        return 1;
    }
    return 3;
}

int ispossible(int x, int y){
    string s = a[x] + a[y];
    stack<char>xx;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            xx.push(s[i]);
        }else{
            if(!xx.empty()){
                xx.pop();
            }else{
                return 0;
            }
        }
    }

    if(!xx.empty()){
        return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string x; cin>>x;
        a.push_back(x);
        int p=0,q=0;
        for(int i=0; i<x.size(); i++){
            if(x[i]=='(')p++;
            else q++;
        }
        int d = p-q;
        v.push_back(d);
    }

    //sort(a.begin(), a.end());
    int balanced = 0;
    for(int i=0; i<a.size(); i++){
        int type = fun(i);
        if(type==1){
            openning.push_back(i);
        }else if(type==2){
            cl[abs(v[i])].insert(i);
        }else{
            balanced++;
        }
    }

    int ans = 0;
    ans += balanced/2;

    for(int i=0; i<openning.size(); i++){
        int id = openning[i];
        int vx = v[id];
        if(!cl[vx].empty()){
            for(auto u:cl[vx]){
                if(ispossible(id,u)){
                    //cout<<id<<" "<<u<<endl;
                    cl[vx].erase(u);
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    //main();
    return 0;
}

