#include<bits/stdc++.h>
using namespace std;
vector<int>wi[55];
vector<int>lo[55];
int cnt[55];
int main()
{
    int n,x,y,s,t,flag,winner,loser,sz1,sz2,m;

    while(cin >> n)
    {
        memset(cnt,0,sizeof(cnt));
        m = (n*(n-1))/2;
        for(int i=1; i<m; i++){
            cin >> x >> y;
            cnt[x]++;
            cnt[y]++;
            wi[x].push_back(y);
            lo[y].push_back(x);
        }

        for(int i=1; i<=n; i++){
            if(cnt[i]<n-1){
                x=i;
                break;
            }
        }
        for(int i=x+1; i<=n; i++){
            if(cnt[i]<n-1){
                y=i;
                break;
            }
        }
        //printf("partha");
        sz1=wi[x].size();
        flag=0;

        for(int i=0; i<sz1; i++)
        {
            s=wi[x][i];
            sz2 = lo[y].size();
            for(int j=0; j<sz2; j++)
            {
                t = lo[y][j];

                if(s==t){
                    winner=x;
                    loser=y;
                    flag=1;
                    goto label;
                }
            }
        }

        sz1=lo[x].size();

        for(int i=0; i<sz1; i++)
        {
            s=lo[x][i];
            sz2 = wi[y].size();
            for(int j=0; j<sz2; j++)
            {
                t = wi[y][j];

                if(s==t){
                    winner=y;
                    loser=x;
                    flag=1;
                    goto label;
                }
            }
        }

        label:

        if(flag==0){
            winner=x;
            loser=y;
        }

        cout << winner << " " << loser << endl;

        for(int i=1; i<=n; i++){
            wi[i].clear();
            lo[i].clear();
        }
    }

    return 0;
}
