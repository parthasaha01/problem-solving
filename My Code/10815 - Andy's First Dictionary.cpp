#include<bits/stdc++.h>
using namespace std;
set<string>vv;
int main()
{
    ios :: sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin>>s)
    {
        for(int i=0; i<s.size(); i++){
            if((s[i]>='a'&&s[i]<='z')||((s[i]>='A'&&s[i]<='Z'))){
                if((s[i]>='A'&&s[i]<='Z')){
                    s[i]+=32;
                }
            }
            else{
                s[i]=' ';
            }
        }

        string p="";
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(p!=""){
                    vv.insert(p);
                }
                p="";
            }
            else{
                p+=s[i];
            }
        }
        if(p!=""){
            vv.insert(p);
        }
    }

    set<string>::iterator it;
    for(it=vv.begin(); it!=vv.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}
