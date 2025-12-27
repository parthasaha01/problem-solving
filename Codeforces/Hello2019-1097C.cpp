#include<bits/stdc++.h>
using namespace std;
vector<string>a;
vector<int>v;
vector<int>openning,closing;
int op[500005], cl[500005];
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

int calc(int id){
    int open=0,close=0;
    for(int i=0; i<a[id].size(); i++){
        if(a[id][i]=='(')open++;
        else open--;

        if(open<0){
            open = 0;
            close++;
        }
    }

    if(open>0 && close>0)return 0;
    if(open==0 && close==0)return 0;
    if(open>0) return open;
    return -close;
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
            closing.push_back(i);
        }else{
            balanced++;
        }
    }

    int ans = 0;
    ans += (balanced/2);

    for(int i=0; i<openning.size(); i++){
        int id = openning[i];
        int need = calc(id);
        if(need>0){
            op[need]++;
        }else if(need<0){
            cl[abs(need)]++;
        }
    }

    for(int i=0; i<closing.size(); i++){
        int id = closing[i];
        int need = calc(id);
        if(need>0){
            op[need]++;
        }else if(need<0){
            cl[abs(need)]++;
        }
    }

    for(int i=0; i<=500000; i++){
        ans += min(op[i],cl[i]);
    }
    cout << ans << endl;
    //main();
    return 0;
}

