#include<bits/stdc++.h>
using namespace std;
#define psi pair<string,int>
#define pii pair<int,int>
string s;
vector<string>ans;
vector<string>vv;
map<int,int>mp;
vector<psi>pp;
vector<pii>ret;
bool cmp(psi x, psi y){
    if(x.second==y.second){
        return x.first.size() < y.first.size();
    }
    return x.second < y.second;
}
bool comp(pii x,pii y){
    if(x.second==y.second){
        return x.first < y.first;
    }
    return x.second > y.second;
}
void fun(int pos, string ss){
    if(pos==0){
        vv.push_back(ss);
        return;
    }

    string temp = ss;
    temp+='.';
    fun(pos-1,temp);
    temp = ss;
    temp += '-';
    fun(pos-1,temp);
}
int calc(string ss) {
    int val = 0;
    for(int i=0; i<ss.size(); i++) {
        if(ss[i]=='.') val+=1;
        else val += 3;
    }
    val += (int)ss.size()-1;
    return val;
}
void precalc() {
    for(int i=1; i<=6; i++) {
        fun(i,"");
    }

    for(int i=0; i<vv.size(); i++){
        int val = calc(vv[i]);
        pp.push_back(make_pair(vv[i],val));
    }

    sort(pp.begin(), pp.end(), cmp);

//    for(int i=0; i<50; i++){
//        cout<<pp[i].first<<" = "<<pp[i].second<<endl;
//    }
}
void solve(){
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='a' && s[i]<='z'){
            s[i] -= 32;
        }else if(s[i]>='0' && s[i]<='9'){
            s[i] += 100;
        }
    }

    mp.clear();
    for(int i=0; i<s.size(); i++) {
        mp[(int)s[i]]++;
    }

    ret.clear();
    for(int i='A'; i<='Z'; i++){
        //printf("%c - %d\n",i,mp[i]);
        ret.push_back(make_pair(i,mp[i]));
    }
    for(int i='0'+100; i<='9'+100; i++){
        //printf("%c - %d\n",i,mp[i]);
        ret.push_back(make_pair(i,mp[i]));
    }
//    printf("space - %d\n",mp[32]);

    sort(ret.begin(), ret.begin(), comp);

    ans.clear();
    for(int i=0; i<36; i++){
        ans.push_back("");
    }

    for(int i=0; i<ret.size(); i++) {
        if(ret[i].first<100) {
            int id = ret[i].first;
            id -= 65;
            ans[id] = pp[i].first;
        }else{
            int id = ret[i].first;
            id -= 100+'0';
            id += 26;
            ans[id] = pp[i].first;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int ks=0; ks<36; ks++) {
        cin>>s;
        int val = calc(s);
        if(ks<26) {
            printf("%c = %d\n",ks+'A',val);
        }else{
            printf("%c = %d\n",ks+22,val);
        }
    }


    return 0;
}

