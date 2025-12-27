#include<bits/stdc++.h>
using namespace std;
string s[10];
int n,m,a[10][10],b[10][10];
int fx[]={-1,-1,-1,+0,+0,+0,+1,+1,+1};
int fy[]={-1,+0,+1,-1,+0,+1,-1,+0,+1};
void toggle(int x,int y)
{
    for(int k=0; k<9; k++)
    {
        int tx = x+fx[k];
        int ty = y+fy[k];
        if(tx>=0 && tx<n && ty>=0 && ty<m){
            b[tx][ty] ^= 1;
        }
    }
}
int fun(int mask1,int mask2)
{
    if((mask1&1)!=(mask2&1))return 10000000;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            b[i][j]=a[i][j];
        }
    }

    int ret = 0;
    for(int j=0; j<m; j++){
        if(mask1&(1<<j)){
            toggle(0,j);
            ret++;
        }
    }

    for(int i=1; i<n; i++){
        if(mask2&(1<<i)){
            toggle(i,0);
            ret++;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(b[i-1][j-1]==0){
                toggle(i,j);
                ret++;
            }
        }
    }

    int flag = 1;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(b[i][j]==0){
                flag = 0;
                break;
            }
        }
    }

    if(flag)return ret;
    return 10000000;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)cin>>s[i];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(s[i][j]=='*')a[i][j]=1;
                else a[i][j]=0;
            }
        }

        int minn = 10000000;
        for(int mask1=0; mask1<(1<<m); mask1++)
        {
            for(int mask2=0; mask2<(1<<n); mask2++)
            {
                int ret = fun(mask1,mask2);

                minn = min(minn,ret);
            }
        }

        if(minn>1000){
            printf("Case %d: impossible\n",ks);
        }
        else{
            printf("Case %d: %d\n",ks,minn);
        }
    }
    return 0;
}
