#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    string s; cin>>s;

    int A=0,F=0,I=0;
    for(int i=0; i<n; i++){
        if(s[i]=='A')A++;
        if(s[i]=='F')F++;
        if(s[i]=='I')I++;
    }

    if(I==0)cout << A << endl;
    else if(I==1) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
