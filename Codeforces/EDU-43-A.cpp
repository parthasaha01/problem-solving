#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s,p;
    cin>>s;

    if(s=="0" || s=="1"){
        cout << s << endl;
        return 0;
    }

    int one=0;
    int zero=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1')one++;
        else zero++;
    }

    if(zero==0){
         cout << "1" << endl;
        return 0;
    }
    else{
        //zero--;

        p+='1';

        for(int i=1; i<=zero; i++){
            p+='0';
        }

        cout << p << endl;
        return 0;
    }

    return 0;

}
