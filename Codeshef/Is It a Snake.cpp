#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
int n,cnt,pp;
int vis[3][505];
string ss[3];
bool valid(int i, int j)
{
    if(i>=0 && i<=1 && j>=0 && j<n && ss[i][j]=='#' && vis[i][j]==false)
        return true;
    return false;
}
void dfs1(int i,int j)
{
    vis[i][j]=true;
    pp++;

    for(int k=0; k<4; k++)
    {
        int ii = i+fx[k];
        int jj = j+fy[k];

        if(valid(ii,jj)){
            dfs1(ii,jj);
        }
    }
}
int dfs(int i,int j,int sum)
{
    vis[i][j]=true;

    int ret=0,qq=0;

    for(int k=0; k<4; k++)
    {
        int ii = i+fx[k];
        int jj = j+fy[k];
        if(valid(ii,jj)){
            qq++;
            ret |= dfs(ii,jj,sum+1);
        }
    }

    //vis[i][j]=false;

    if(qq==0){
        if(sum==cnt)return 1;
        else return 0;
    }
    else{
        return ret;
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);

        for(int i=0; i<=1; i++)cin >> ss[i];

        cnt=0;
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                if(ss[i][j]=='#'){
                    cnt++;
                }
            }
        }

        pp=0;
        bool flag = true;
        memset(vis,false,sizeof(vis));
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                if(ss[i][j]=='#'){
                    dfs1(i,j);
                    goto label;
                }
            }
        }

        label:

        //cout << cnt << " " << pp << endl;

        if(pp!=cnt){
            printf("no\n"); continue;
        }

        int ans=0;
        memset(vis,false,sizeof(vis));
        for(int j=0; j<n; j++){
            if(ss[0][j]=='#'){
                ans = dfs(0,j,1);
                break;
            }
        }

        if(ans==1){
            printf("yes\n"); continue;
        }

        memset(vis,false,sizeof(vis));
        for(int j=n-1; j>=0; j--){
            if(ss[0][j]=='#'){
                ans = dfs(0,j,1);
                break;
            }
        }

        if(ans==1){
            printf("yes\n"); continue;
        }

        memset(vis,false,sizeof(vis));
        for(int j=n-1; j>=0; j--){
            if(ss[1][j]=='#'){
                ans = dfs(1,j,1);
                break;
            }
        }

        if(ans==1){
            printf("yes\n"); continue;
        }

        memset(vis,false,sizeof(vis));
        for(int j=0; j<n; j++){
            if(ss[1][j]=='#'){
                ans = dfs(1,j,1);
                break;
            }
        }

        if(ans==1){
            printf("yes\n"); continue;
        }

        printf("no\n");

    }
    return 0;
}

/*
20

2
##
..

2
##
.#

2
#.
.#

7
#.###..
#######

6
##.#..
.###..

5
##.##
.#.#.

6
####..
######

6
######
####..

7
####.#.
#######

*/
