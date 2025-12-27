#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t,x;
    cin>>s;
    //t = s;

    // 111100011122212212102201122201222111
    int n = s.size();

    int zero=0;
    int one=0;
    int two=0;

    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            for(int k=1; k<=one; k++){
                t+='1';
            }
            for(int k=1; k<=two; k++){
                t+='2';
            }
            t+='0';
            one=0;
            two=0;
        }
        else if(s[i]=='1'){
            one++;
        }
        else{
            two++;
        }
    }

    for(int k=1; k<=one; k++){
        t+='1';
    }
    for(int k=1; k<=two; k++){
        t+='2';
    }

    one=0;
    zero=0;
    for(int i=0; i<n; i++){
        if(t[i]=='2'){
            for(int k=1; k<=zero; k++){
                x+='0';
            }
            for(int k=1; k<=one; k++){
                x+='1';
            }
            x+='2';
            one=0;
            zero=0;
        }
        else if(t[i]=='1'){
            one++;
        }
        else{
            zero++;
        }
    }

    for(int k=1; k<=zero; k++){
        x+='0';
    }
    for(int k=1; k<=one; k++){
        x+='1';
    }

    cout<<x<<endl;


    //main();
    return 0;
}

