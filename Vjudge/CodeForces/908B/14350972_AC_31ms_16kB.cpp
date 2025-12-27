#include<bits/stdc++.h>
using namespace std;
string a,s[55];
int n,m,sx,sy,dx,dy;
int fx[]={-1,+1,+0,+0};
int fy[]={+0,+0,-1,+1};
int possible(vector<int>v)
{
    map<int,int>mp;
    mp[v[0]] = 0;
    mp[v[1]] = 1;
    mp[v[2]] = 2;
    mp[v[3]] = 3;

    //cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    //cout << mp[0] << " " << mp[1] << " " << mp[2] << " " << mp[3] << endl;
    //cout << sx << " " << sy << " " << dx << " " << dy << endl << endl;

    int x = sx, y = sy;

    for(int i=0; i<a.size(); i++){
        x = x+fx[mp[a[i]-'0']];
        y = y+fy[mp[a[i]-'0']];
        if(x<0||x>=n||y<0||y>=m)return 0;
        if(s[x][y]=='#')return 0;
        if(x==dx&&y==dy)return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++)cin>>s[i];
    cin>>a;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j]=='S')sx=i,sy=j;
            if(s[i][j]=='E')dx=i,dy=j;
        }
    }

    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    int ans = 0;

    do{
        if(possible(v))ans++;
    }while(next_permutation(v.begin(),v.end()));

    cout << ans << endl;

    return 0;
}
