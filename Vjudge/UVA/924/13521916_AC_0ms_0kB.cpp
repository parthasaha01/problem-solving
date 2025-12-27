#include<bits/stdc++.h>
using namespace std;
int n,maxx,day,d[2505],cnt[2505];
vector<int>ed[2505];
queue<int>q;
void BFS(int s)
{
    for(int i=0; i<n; i++)d[i]=100000,cnt[i]=0;
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                cnt[d[v]]++;
                q.push(v);
            }
        }
    }
    maxx=0;
    for(int i=1; i<=n; i++){
        if(cnt[i]>maxx){
            maxx=cnt[i];
            day=i;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int u=0; u<n; u++){
        int k; scanf("%d",&k);
        while(k--){
            int v; scanf("%d",&v);
            ed[u].push_back(v);
        }
    }
    int t; scanf("%d",&t);
    while(t--)
    {
        int s; scanf("%d",&s);
        if(ed[s].size()==0){
            printf("0\n");
            continue;
        }
        BFS(s);
        printf("%d %d\n",maxx,day);
    }
    return 0;
}
