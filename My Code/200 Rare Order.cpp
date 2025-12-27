#include<bits/stdc++.h>
using namespace std;
string s[5000];
char res[30];
int vis[30];
vector<char>v[30];
int main()
{
    int n=0;
    int sz, maxx=0;

    while(cin >> s[n])
    {
        if(s[n]=="#"){
            break;
        }

        sz = s[n].size();
        if(sz>maxx){
            maxx=sz;
        }
        for(int i=0; i<sz; i++){
            v[i].push_back(s[n][i]);
        }
        n++;
    }
    int k=0;

    for(int i=0; i<maxx; i++)
    {
        sz = v[i].size();

        for(int j=0; j<sz; j++)
        {
            int val = v[i][j]-'A';

            if(vis[val]==0)
            {
                res[k++] = v[i][j];
                vis[val]=1;
            }
        }
        //printf("maxx=%d\n",maxx);
    }
    res[k]='\0';
    cout << res << endl;

    for(int i=0;i<30;i++){
        v[i].clear();
    }
    memset(vis,0,sizeof(vis));

    return 0;
}
