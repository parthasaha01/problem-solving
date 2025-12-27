#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[105][105];
int lcs(int i,int j)
{
    if(i==a.size())return (b.size()-j);
    if(j==b.size())return (a.size()-i);

    if(dp[i][j] != -1)return dp[i][j];

    int ret,ret1,ret2,ret3;

    if(a[i]==b[j]){
        ret = lcs(i+1,j+1);
    }
    else{
        ret1 = 1+lcs(i+1,j+1); // replace
        ret2 = 1+lcs(i,j+1);    // insert
        ret3 = 1+lcs(i+1,j);    // delete

        ret = min(ret1,min(ret2,ret3));
    }
    return dp[i][j] = ret;
}
void path(int i,int j,int p)
{
    if(i==a.size()){
        for(int k=j; k<b.size(); k++,p++){
            printf("%d Insert %d,%c\n",p,k+1,b[k]);
        }
        return;
    }
    if(j==b.size()){
            for(int k=i; k<a.size(); k++,p++){
            printf("%d Delete %d\n",p,j+1);
        }
        return;
    }

    int ret,ret1,ret2,ret3;

    if(a[i]==b[j]){
        path(i+1,j+1,p);
    }
    else{
        ret1 = 1+lcs(i,j+1);    // insert
        ret2 = 1+lcs(i+1,j);    // delete
        ret3 = 1+lcs(i+1,j+1); // replace

        ret = lcs(i,j);

        if(ret1==ret){
            printf("%d Insert %d,%c\n",p,j+1,b[j]);
            path(i,j+1,p+1);
        }
        else if(ret2==ret){
            printf("%d Delete %d\n",p,j+1);
            path(i+1,j,p+1);
        }
        else{
            printf("%d Replace %d,%c\n",p,j+1,b[j]);
            path(i+1,j+1,p+1);
        }
    }
}
int main()
{
    int ks=0;
    while(getline(cin,a))
    {
//        while(a.size()==0){
//            getline(cin,a);
//        }
        getline(cin,b);
//        while(b.size()==0){
//            getline(cin,b);
//        }

        if(ks)printf("\n");ks++;

        memset(dp,-1,sizeof(dp));
        int mn = lcs(0,0);
        printf("%d\n",mn);
        path(0,0,1);
    }
    return 0;
}
