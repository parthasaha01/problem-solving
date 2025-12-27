#include<bits/stdc++.h>
using namespace std;
#define pii
vector<string>a;
vector<int>v,t;
vector<int>openning, closing, balanced, confused;
set<int>cl[500005];
int fun(string s){
    stack<char>x;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            x.push(s[i]);
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
    int type = fun(s);
    if(type==3)return 1;
    else return 0;
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

    for(int i=0; i<a.size(); i++){
        int type = fun(a[i]);
        if(type==1){
            openning.push_back(i);
            //t.push_back(1);
            //op[abs(v[i])].insert(i);
        }else if(type==2){
            closing.push_back(i);
            //t.push_back(2);
            cl[abs(v[i])].insert(i);
        }else if(type==3){
            balanced.push_back(i);
            //t.push_back(3);
        }else{
            confused.push_back(i);
            //t.push_back(0);
        }
    }

//    cout<<"Openning: ";
//    for(int i=0; i<openning.size(); i++){
//        cout << openning[i] << " ";
//    }
//    cout<<endl;
//
//    cout<<"Closing: ";
//    for(int i=0; i<closing.size(); i++){
//        cout << closing[i] << " ";
//    }
//    cout<<endl;
//
//    cout<<"Balanced: ";
//    for(int i=0; i<balanced.size(); i++){
//        cout << balanced[i] << " ";
//    }
//    cout<<endl;

    int ans = 0;
    ans += ((int)balanced.size()) / 2;

    for(int i=0; i<openning.size(); i++){
        int id = openning[i];
        int vx = v[id];
        if(!cl[vx].empty()){
            for(auto u:cl[vx]){
                //cout << id << " " << u << endl;
                if(ispossible(id,u)){
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



