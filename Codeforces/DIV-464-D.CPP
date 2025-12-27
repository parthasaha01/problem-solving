#include<bits/stdc++.h>
using namespace std;
string u,v;
int n;
int par[30];
pair<int,int> pii;
vector< pair<int,int> >vv;
int Find(int x)
{
    if(par[x]==x)return x;
    return par[x] = Find(par[x]);
}
void Union(int x,int y)
{
    par[Find(y)] = Find(x);
}
int main()
{
    cin>>n;
    cin>>u;
    cin>>v;

    for(int i=0; i<=26; i++)par[i]=i;
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        int x = u[i]-'a';
        int y = v[i]-'a';

        if(x==y)continue;

        int a = Find(x);
        int b = Find(y);

        if(a!=b){
            ans++;
            Union(a,b);
            vv.push_back(make_pair(x,y));
        }
    }

    printf("%d\n",ans);
    for(int i=0; i<ans; i++)
    {
        //pii pr = vv[i];
        printf("%c %c\n",vv[i].first+'a',vv[i].second+'a');
    }
    return 0;
}
