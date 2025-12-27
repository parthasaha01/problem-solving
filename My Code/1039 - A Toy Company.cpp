#include<bits/stdc++.h>
using namespace std;
int forbid[26][26][26], vis[26][26][26], d[26][26][26];
int BFS(string s, string t){
    if(forbid[s[0]-'a'][s[1]-'a'][s[2]-'a']==1) return -1;
    if(forbid[t[0]-'a'][t[1]-'a'][t[2]-'a']==1) return -1;
    if(s==t) return 0;

    queue<string>q;
    q.push(s);
    vis[s[0]-'a'][s[1]-'a'][s[2]-'a'] = 1;
    d[s[0]-'a'][s[1]-'a'][s[2]-'a'] = 0;

    while(!q.empty()){
        string u = q.front();
        q.pop();

        int c1=u[0]-'a', c2=u[1]-'a', c3=u[2]-'a';
        if(u==t)return d[c1][c2][c3];

        int x1,x2;
        if(u[0]=='a'){
            x1=1, x2=25;
        }else if(u[0]=='z'){
            x1=0, x2=24;
        }else{
            x1=c1+1, x2=c1-1;
        }
        if(vis[x1][c2][c3]==0 && forbid[x1][c2][c3]==0){
            d[x1][c2][c3] = d[c1][c2][c3]+1;
            vis[x1][c2][c3] = 1;
            string v; v+=(x1+'a'); v+=(c2+'a'); v+=(c3+'a');
            q.push(v);
        }

        if(vis[x2][c2][c3]==0 && forbid[x2][c2][c3]==0){
            d[x2][c2][c3] = d[c1][c2][c3]+1;
            vis[x2][c2][c3] = 1;
            string v; v+=(x2+'a'); v+=(c2+'a'); v+=(c3+'a');
            q.push(v);
        }

        if(u[1]=='a'){
            x1=1, x2=25;
        }else if(u[1]=='z'){
            x1=0, x2=24;
        }else{
            x1=c2+1, x2=c2-1;
        }
        if(vis[c1][x1][c3]==0 && forbid[c1][x1][c3]==0){
            d[c1][x1][c3] = d[c1][c2][c3]+1;
            vis[c1][x1][c3] = 1;
            string v; v+=(c1+'a'); v+=(x1+'a'); v+=(c3+'a');
            q.push(v);
        }

        if(vis[c1][x2][c3]==0 && forbid[c1][x2][c3]==0){
            d[c1][x2][c3] = d[c1][c2][c3]+1;
            vis[c1][x2][c3] = 1;
            string v; v+=(c1+'a'); v+=(x2+'a'); v+=(c3+'a');
            q.push(v);
        }

        if(u[2]=='a'){
            x1=1, x2=25;
        }else if(u[2]=='z'){
            x1=0, x2=24;
        }else{
            x1=c3+1, x2=c3-1;
        }
        if(vis[c1][c2][x1]==0 && forbid[c1][c2][x1]==0){
            d[c1][c2][x1] = d[c1][c2][c3]+1;
            vis[c1][c2][x1] = 1;
            string v; v+=(c1+'a'); v+=(c2+'a'); v+=(x1+'a');
            q.push(v);
        }

        if(vis[c1][c2][x2]==0 && forbid[c1][c2][x2]==0){
            d[c1][c2][x2] = d[c1][c2][c3]+1;
            vis[c1][c2][x2] = 1;
            string v; v+=(c1+'a'); v+=(c2+'a'); v+=(x2+'a');
            q.push(v);
        }

    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++){
        memset(forbid,0,sizeof(forbid));
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));

        string s,t; cin>>s>>t;
        int n; cin>>n;
        while(n--){
            string x,y,z; cin>>x>>y>>z;
            for(int i=0; i<x.size(); i++){
                for(int j=0; j<y.size(); j++){
                    for(int k=0; k<z.size(); k++){
                        forbid[x[i]-'a'][y[j]-'a'][z[k]-'a']=1;
                    }
                }
            }
        }
        cout<<"Case "<<ks<<": "<<BFS(s,t)<<endl;
    }
    return 0;
}
