#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
    long long int T, N, i, L;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> s;
        L=s.length();

        if(s=="1" || s=="4" || s=="78")
            cout<<"+"<<endl;
        else if(s[L-1]=='5' && s[L-2]=='3')
            cout<<"-"<<endl;
        else if(s[L-1]=='4' && s[0]=='9')
            cout<<"*"<<endl;
        else if(s[0]=='1' && s[1]=='9' && s[2]=='0')
            cout<<"?"<<endl;
    }

    return 0;
}
