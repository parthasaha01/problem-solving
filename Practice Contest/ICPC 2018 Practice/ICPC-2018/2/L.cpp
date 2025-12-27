#include<bits/stdc++.h>
using namespace std;
string fun(char ch,int n,int mul,int add){
    for(int i=0; i<26; i++){

    }
    string s;
    s += ch;
    for(int i=1; i<n; i++){
        int id = ch-'a';
        int v = ((id*mul) + (i*add))%26;
        ch = v+'a';
        s += ch;
    }
    return s;
}
int main(){
    char ch;
    int n,mul,add;
    while(cin>>ch>>n>>mul>>add){
        string s = fun(ch,n,mul,add);
        cout << s << endl << endl;
    }
    return 0;
}
