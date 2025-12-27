#include<bits/stdc++.h>
using namespace std;
string s[2];
int n,a[2][105],b[2][105];
int check0(int i){
    if(i<0 || i>=n)return 0;
    if(a[0][i]==0)return 1;
    else return 0;
}
int check1(int i){
    if(i<0 || i>=n)return 0;
    if(a[1][i]==0)return 1;
    else return 0;
}
int main()
{
    cin>>s[0];
    cin>>s[1];

    n = s[0].size();

    for(int i=0; i<s[0].size(); i++){
        if(s[0][i]=='0')a[0][i] = 0;
        else a[0][i] = 1;
    }

    for(int i=0; i<s[1].size(); i++){
        if(s[1][i]=='0')a[1][i] = 0;
        else a[1][i] = 1;
    }



    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            b[i][j] = a[i][j];
        }
    }

    int ans = 0;
    int n = s[0].size();

    for(int i=0; i<n; i++)
    {
        if(a[0][i]==1)continue;
        if(check0(i-1) && check1(i-1)){
            a[0][i] = 1;
            a[0][i-1] = 1;
            a[1][i-1] = 1;
            ans++;
        }
        else if(check1(i-1)&&check1(i)){
            a[0][i] = 1;
            a[1][i-1] = 1;
            a[1][i] = 1;
            ans++;
        }
        else if(check1(i)&&check1(i+1)){
            a[0][i] = 1;
            a[1][i] = 1;
            a[1][i+1] = 1;
            ans++;
        }
        else if(check0(i+1) && check1(i+1)){
            a[0][i] = 1;
            a[0][i+1] = 1;
            a[1][i+1] = 1;
            ans++;
        }
    }

    cout << ans << endl;

    //main();

    return 0;
}
