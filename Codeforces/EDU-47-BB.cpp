#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t,x;
    cin>>s;
    //t = s;

    // 111100011122212212102201122201222111
    int n = s.size();

    int on=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1')on++;
    }
    int zr=0;
    for(int i=0; i<n; i++){
        if(s[i]=='2'){
            for(int k=1; k<=zr; k++){
                x+='0';
            }
            for(int k=1; k<=on; k++){
                x+='1';
            }
            zr=0;
            on=0;
            for(int j=i; j<n; j++){
                if(s[j]=='0')x+='0';
                if(s[j]=='2')x+='2';
            }
            break;
        }
        if(s[i]=='0')zr++;
    }

    for(int k=1; k<=zr; k++){
        x+='0';
    }
    for(int k=1; k<=on; k++){
        x+='1';
    }

    cout<<x<<endl;

    //main();
    return 0;
}


