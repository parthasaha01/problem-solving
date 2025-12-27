#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int fun(){
    int sml=0, cap=0, nn=0;
    for(int i=0; i<n; i++){
        if(s[i]>='A'&&s[i]<='Z')cap++;
        else if(s[i]>='a'&&s[i]<='z')sml++;
        else nn++;
    }
    if(cap<=k && sml<=k)return 2;
    //if(cap==0)return 0;
    //if(sml==0)return 1;
    if(cap<=k) return 0;
    if(sml<=k) return 1;
    return 3;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s;
        int f = fun();
        if(f==0)cout<<"chef"<<endl;
        else if(f==1)cout<<"brother"<<endl;
        else if(f==2)cout<<"both"<<endl;
        else cout<<"none"<<endl;
    }
    return 0;
}
