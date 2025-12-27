#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string ss="CODEFORCES";

    while(cin>>s)
    {
        if(s.size()<ss.size()){
            cout << "NO" << endl;
            continue;
        }

        string fst=s.substr(0,ss.size());
        if(fst==ss){
            cout << "YES" << endl;
            continue;
        }

        string lst=s.substr(s.size()-ss.size(),ss.size());
        if(lst==ss){
            cout << "YES" << endl;
            continue;
        }

        string mid;
        for(int i=0,k=0; i<s.size(); i++){
            if(s[i]==ss[k]){
                mid+=s[i];
                k++;
            }
            else
                break;
        }
        string temp=ss.substr(mid.size(),ss.size()-mid.size());
        string mdl=s.substr(s.size()-temp.size(),temp.size());
        if(mdl==temp){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

    return 0;
}
