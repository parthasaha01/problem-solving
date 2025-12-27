#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int n,d,r,rgt[2][mx],vs[mx];
string s;
vector<int>v;
queue<int>qd;
queue<int>qr;
void precal()
{
    int m = v.size();

    d=0, r=0;
    for(int i=1; i<m; i++){
        if(v[i]==0)d++;
        if(v[i]==1)r++;
    }

    int cur = m;
    for(int i=m-1; i>0; i--){
        rgt[0][i] = cur;
        if(v[i]==0)cur = i;
    }

    cur = m;
    for(int i=m-1; i>0; i--){
        rgt[1][i] = cur;
        if(v[i]==1)cur = i;
    }

    while(!qd.empty())qd.pop();
    while(!qr.empty())qr.pop();
}
string solve()
{
    if(d>=(r+r))return "D";
    if(r>=(d+d))return "R";

    while(1)
    {
        int m = v.size();
        memset(vs,-1,sizeof(vs));
        int nd=0,nr=0;
        for(int i=1; i<m; i++)
        {
            if(nd<=i)nd = rgt[0][i];
            if(nr<=i)nr = rgt[1][i];
            if(vs[i]==2)continue;

            int x = v[i];

            if(x==0){
                int w = nr;
                if(w<m){
                    vs[w] = 2;
                    nr = rgt[1][nr];
                    r--;
                }
                else{
                    if(qr.empty())return "D";
                    int pr = qr.front();
                    qr.pop();
                    vs[pr] = 2;
                    r--;
                }
                vs[i] = 0;
                qd.push(i);
            }
            else if(x==1){
                int w = nd;
                if(w<m){
                    vs[w] = 2;
                    nd = rgt[0][nd];
                    d--;
                }
                else{
                    if(qd.empty())return "R";
                    int pd = qd.front();
                    qd.pop();
                    vs[pd] = 2;
                    d--;
                }
                qr.push(i);
                vs[i] = 1;
            }

            if(d>=(r+r))return "D";
            if(r>=(d+d))return "R";
        }

        v.clear();
        v.push_back(-1);
        for(int i=1; i<m; i++){
            if(vs[i]==0)v.push_back(0);
            if(vs[i]==1)v.push_back(1);
        }
        precal();
    }

    if(d>=(r+r))return "D";
    if(r>=(d+d))return "R";
}
int main()
{
    cin>>n;
    cin>>s;
    s = "0"+s;

    v.push_back(-1);
    for(int i=1; i<=n; i++){
        if(s[i]=='D'){
            v.push_back(0);
        }
        if(s[i]=='R'){
            v.push_back(1);
        }
    }

    precal();

    string ans;
    ans = solve();
    cout << ans << endl;
    return 0;
}
