#include<bits/stdc++.h>
using namespace std;
string s;
vector<string>vv;
int n;
void fun(int pos, string ss)
{
    if(pos==n-1){
        ss+="#";
        vv.push_back(ss);
        return;
    }

    char prev = ss[pos-1];
    if(s[pos]=='W'){
        if(ss[pos-1]!='B' && s[pos+1]!='B'){
            string pp = ss;
            pp += 'B';
            fun(pos+1, pp);
        }
        if(ss[pos-1]!='G' && s[pos+1]!='G'){
            string pp = ss;
            pp += 'G';
            fun(pos+1, pp);
        }
        if(ss[pos-1]!='R' && s[pos+1]!='R'){
            string pp = ss;
            pp += 'R';
            fun(pos+1, pp);
        }
    }
    else{
        string pp = ss;
        pp += s[pos];
        fun(pos+1, pp);
    }
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        cin >> s;
        s = "#" + s + "#";
        n = s.size();
        fun(1,"#");

        int sz = vv.size();
        printf("sz=%d\n",sz);
//        for(int i=0; i<vv.size(); i++){
//            cout << vv[i] << endl;
//        }
        vv.clear();
       cout << endl;
    }
    return 0;
}
