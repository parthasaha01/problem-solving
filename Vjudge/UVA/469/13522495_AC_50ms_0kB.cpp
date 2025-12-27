#include<bits/stdc++.h>
using namespace std;
int r,c,vis[105][105];
string ss[105];
int fx[]={-1,-1,+0,+0,+1,+1,+1,-1};
int fy[]={-1,+0,-1,+1,+0,+1,-1,+1};
int BFS(int x,int y)
{
    if(ss[x][y]=='L')return 0;

    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    queue< pair<int,int> >q;
    q.push(make_pair(x,y));
    int cnt=0;

    while(!q.empty())
    {
        pair<int,int> u;
        u = q.front();
        q.pop();
        x = u.first;
        y = u.second;
        cnt++;

        for(int k=0; k<8; k++)
        {
            int tx = x+fx[k];
            int ty = y+fy[k];

            if(tx<0||tx>=r||ty<0||ty>=c)continue;
            if(ss[tx][ty]=='L')continue;
            if(vis[tx][ty]==1)continue;

            vis[tx][ty]=1;
            q.push(make_pair(tx,ty));
        }
    }
    return cnt;
}
int main()
{
    int tt,ks=0; cin>>tt;
    getchar();
    getchar();
    while(tt--)
    {
        if(ks)printf("\n");
        ks++;
        int n=0;
        while(getline(cin,ss[n]))
        {
            if(ss[n]=="")break;
            else if(ss[n][0]=='L'||ss[n][0]=='W'){
                c = ss[n].size();
                n++;
                r = n;
            }
            else{
                stringstream s;
                s << ss[n];
                int a[5], i = 0;
                while(s >> a[i++]);
                int x=a[0],y=a[1];

                int ans = BFS(--x,--y);

                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

