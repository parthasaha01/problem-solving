#include<bits/stdc++.h>
using namespace std;
string ss,rr;
int sz,dp[1005][1005];
int lcs(int i,int j)
{
    if(i==sz)return (sz-j);
    if(j==sz)return (sz-i);

    if(dp[i][j]!=-1)return dp[i][j];

    int ret=10000000;
    if(ss[i]==rr[j]){
        ret = lcs(i+1,j+1);
    }
    else{
        int ret1 = 1+lcs(i+1,j+1); // replace
        int ret2 = 1+lcs(i,j+1);    // insert in ss at position i
        int ret3 = 1+lcs(i+1,j);   // insert in rr at position j
        //int ret4 = 1+lcs(i+1,j);    // delete position i at ss
        //int ret5 = 1+lcs(i,j+1);    // delete position j at rr
        ret = min(ret1,min(ret2,ret3));
    }

    return dp[i][j]=ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        cin >> ss;
        rr = ss;
        reverse(rr.begin(), rr.end());
        sz = ss.size();

        //cout << ss << endl << rr << endl;

        memset(dp,-1,sizeof(dp));
        int ans = lcs(0,0);
        ans /= 2;
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
