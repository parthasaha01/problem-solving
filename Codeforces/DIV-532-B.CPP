#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],mp[100005];
string s;
void fun(){
    unordered_set<int>ss;
    memset(mp,0,sizeof(mp));
    s="";
    for(int i=1; i<=m; i++){
        ss.insert(a[i]);
        if((int)ss.size()==n){
            s += '1';
            ss.clear();
            for(int j=1; j<=n; j++){
                mp[j]--;
                if(mp[j]>0)ss.insert(j);
            }
        }else{
            s += '0';
            mp[a[i]]++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)cin>>a[i];
    fun();
    cout<<s<<endl;

    //main();
    return 0;
}
