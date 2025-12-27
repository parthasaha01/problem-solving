#include<bits/stdc++.h>
using namespace std;
int vis[105][10];
struct data{
    int lv,vv;
    string ss;
};
string BFS(string s)
{
    memset(vis,0,sizeof(vis));
    queue<data>Q;
    data u; u.lv=0; u.vv=0; u.ss="";
    Q.push(u);
    vis[u.lv][u.vv] = 1;
    for(int i=0; i<s.size(); i++)
    {
        while(Q.front().lv<i+1)
        {
            data u = Q.front();
            Q.pop();

            data v;
            v.lv = i+1;
            v.ss = u.ss+s[i];
            v.vv = ((u.vv*10)+(s[i]-'0'))%8;

            if(v.vv==0)return v.ss;
            if(vis[v.lv][v.vv]==0)Q.push(v);
            vis[v.lv][v.vv] = 1;

            v.ss = u.ss;
            v.vv = u.vv;
            if(vis[v.lv][v.vv]==0)Q.push(v);
            vis[v.lv][v.vv] = 1;
        }
    }
    return "NO";
}
int main()
{
    string s; cin>>s;

    string ans = BFS(s);

    if(ans=="NO")cout << "NO" << endl;
    else cout << "YES" << endl << ans << endl;

    return 0;
}
