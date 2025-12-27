#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t,p;
    cin>> s >> t;
    int n = s.size();

    int cnt=0;

    for(int i=0; i<n; i++){
        if(s[i]!=t[i])cnt++;
    }

    if(cnt&1)cout<<"impossible"<<endl;
    else{
        for(int i=0,k=0; i<n; i++){
            if(s[i]==t[i])p+=s[i];
            else{
                if(k)p+=s[i];
                else p+=t[i];
                k=1-k;
            }
        }
        cout<<p<<endl;
    }
    return 0;
}
