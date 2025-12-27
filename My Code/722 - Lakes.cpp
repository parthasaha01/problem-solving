#include<bits/stdc++.h>
using namespace std;
int fx[] = {-1,+0,+0,+1};
int fy[] = {+0,-1,+1,+0};
int ans,n,m,r,c,a[101][101],vis[101][101];
string s[101];
bool IsValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m) return 0;
    if(s[x][y]=='1' || vis[x][y]==1)return 0;
    return 1;
}
void dfs(int x,int y) {
    //cout<<x<<" "<<y<<endl;
    //getchar();
    if(s[x][y]=='1')return;
    ans++;
    vis[x][y] = 1;
    for(int i=0; i<4; i++){
        int tx = x + fx[i];
        int ty = y + fy[i];

        if(IsValid(tx,ty)){
            dfs(tx,ty);
        }
    }
}
int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    string t; getline(cin,t);
    int tt = 0;
    for(int i=0; i<t.size(); i++){
        tt = (tt*10) + (t[i]-'0');
    }

    for(int ks=1; ks<=tt; ks++) {
        cin.ignore();
        string x; getline(cin, x);

        r = 0, c = 0;
        for(int i=0; i<x.size(); i++) {
            if(x[i]==' '){
                for(i=i+1; i<x.size(); i++){
                    c = (c*10) + (x[i]-'0');
                }
            }else {
                r = (r*10) + (x[i]-'0');
            }
        }

        int k = 0;
        while(1){
            getline(cin,s[k]);
            if(s[k]=="")break;
            k++;
        }

        n = k;
        m = s[0].size();

//        cout<<r<<" "<<c<<" "<<k<<endl;
//        for(int i=0; i<k; i++) {
//            cout<<s[i]<<endl;
//        }

        r--, c--;

        ans = 0;
        memset(vis,0,sizeof(vis));
        dfs(r,c);

        //cout<<"partha"<<endl;
        if(ks>1)cout<<endl;

        cout<<ans<<endl;
    }

    return 0;
}
