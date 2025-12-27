#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[55];
int id[205],vis[205];
vector<int>ed[205],vv[205],uu[205];
bool flag;
void DFS(int u,int id)
{
   // if(flag==false)return;

    vis[u] = id;
    //printf("%d ",u+1);
    if(u<100){
        uu[id].push_back(u);
    }
    else{
        vv[id].push_back(u-100);
    }

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==0){
            DFS(v,id);
        }
//        else{
//            if(vis[v]!=id){
//                flag = false;
//                return;
//            }
//        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>s[i];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='#'){
              //  printf("%d %d\n",i+1,j+101);
                ed[i].push_back(j+100);
                ed[j+100].push_back(i);
            }
        }
    }

    int k = 0;
    flag = true;

    for(int i=0; i<n; i++)
    {
        if(vis[i]==0){
            DFS(i,++k);
            //printf("\n");
            //if(flag==false)break;
            sort(uu[k].begin(),uu[k].end());
            sort(vv[k].begin(),vv[k].end());
        }
    }
    for(int i=0; i<m; i++)
    {
        if(vis[i+100]==0){
            DFS(i+100,++k);
            //if(flag==false)break;
            sort(uu[k].begin(),uu[k].end());
            sort(vv[k].begin(),vv[k].end());
        }
    }

//    printf("k=%d\n",k);
//    for(int i=1; i<=k; i++)
//    {
//        for(int j=0; j<uu[i].size(); j++)
//        {
//            printf("%d ",uu[i][j]+1);
//        }
//        printf("   ");
//        for(int j=0; j<vv[i].size(); j++)
//        {
//            printf("%d ",vv[i][j]+1);
//        }
//        printf("\n");
//    }

    flag = true;
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<uu[i].size(); j++)
        {
            int p = uu[i][j];
            for(int x=0; x<vv[i].size(); x++)
            {
                int q = vv[i][x];
                if(s[p][q]=='.'){
                    flag = false;
                    break;
                }
            }
        }
    }

    if(flag)printf("Yes\n");
    else printf("No\n");

    //main();

    return 0;


}
