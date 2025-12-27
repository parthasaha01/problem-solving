#include<bits/stdc++.h>
using namespace std;
int n,one,zero;
string s;
int check()
{
    for(int i=1; i<n; i++){
        if(s[i]=='1'&&s[i-1]=='1')return 0;
    }
    return 1;
}
int fun()
{
    if(s[0]=='0'&&s[1]=='0')return 0;
    if(s[n-1]=='0'&&s[n-2]=='0')return 0;

    for(int i=2; i<n; i++){
        if(s[i]=='0'&&s[i-1]=='0'&&s[i-2]=='0')return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    cin>>s;

    for(int i=0; i<n; i++){
        if(s[i]=='0')zero++;
        else one++;
    }

    if(n==1){
        if(one==0)cout<<"No"<<endl;
        else cout<<"Yes" <<endl;
        return 0;
    }

    if(n==2)
    {
        if(one==1)cout<<"Yes" <<endl;
        else cout<<"No"<<endl;
        return 0;
    }

    if(check()==0)
    {
        cout << "No" << endl;
        return 0;
    }

    if(fun()==0){
        cout << "No" << endl;
        return 0;
    }

    cout<<"Yes" <<endl;
    return 0;
}
