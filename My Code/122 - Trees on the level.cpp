#include<bits/stdc++.h>
using namespace std;
vector<string>vv;
struct dt{
    int v,sz;
    string p;
}st[260];
bool cmp(dt a,dt b)
{
    if(a.sz != b.sz)return a.sz < b.sz;
    return a.p < b.p;
}
void fun(int id)
{
    int len = vv[id].size();
    int val = 0,i;
    for(i=1; i<len; i++){
        if(vv[id][i]==',')break;
        val = (val*10) + (vv[id][i]-'0');
    }
    st[id].v = val;
    int sz = 0;
    string s="A";
    for(i=i+1; i<len-1; i++){
        s += vv[id][i];
    }
    st[id].sz = s.size();
    st[id].p = s;
}
int check(int n)
{
    if(n==1){
        if(st[0].p != "A")return 0;
        return 1;
    }

    map<string,int>mp;
    for(int i=0; i<n; i++){
        if(mp.find(st[i].p)!= mp.end())return 0;
        mp[st[i].p] = 1;
    }

    for(int i=n-1; i>0; i--){
        string s;
        for(int j=0; j<st[i].sz-1; j++) s += st[i].p[j];
        if(mp.find(s)==mp.end())return 0;
    }
    return 1;
}
int main()
{
    ios :: sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin>>s)
    {
        vv.clear();

        vv.push_back(s);
        while(cin>>s){
            if(s=="()")break;
            vv.push_back(s);
        }

        int n = vv.size();

        for(int i=0; i<n; i++){
            fun(i);
        }

        sort(st,st+n,cmp);

//        for(int i=0; i<n; i++){
//            cout << st[i].v << " " << st[i].sz << " " << st[i].p << endl;
//        }

        int f = check(n);

        if(f){
            for(int i=0; i<n; i++){
                if(i==n-1)cout << st[i].v << endl;
                else cout << st[i].v << " ";
            }
        }
        else{
            cout << "not complete" << endl;
        }
    }

    return 0;
}
