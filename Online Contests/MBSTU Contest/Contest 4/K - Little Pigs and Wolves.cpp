#include<bits/stdc++.h>
using namespace std;
int vis[15][15];
string ss[15];
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        for(int i=0; i<n; i++)
        {
            cin >> ss[i];
        }

        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(ss[i][j]=='P')
                {
                    for(int k=0; k<4; k++)
                    {
                        int tx=i+fx[k];
                        int ty=j+fy[k];

                        if(tx>=0 && tx<n && ty>=0 && ty<m && ss[tx][ty]=='W')
                        {
                            ++cnt;
                            ss[tx][ty]='.';
                            break;
                        }
                    }
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
