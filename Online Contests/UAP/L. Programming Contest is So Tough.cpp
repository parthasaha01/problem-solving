#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

//        for(int i=0; i<s.size(); i++){
//            if(s[i]>='A' && s[i]<='Z')s[i] = s[i]+32;
//        }

        if(s=="AdHoc")cout<<"1"<<endl;
        else if(s=="DataStructures")cout<<"2"<<endl;
        else cout<<"3"<<endl;
    }
    return 0;
}

