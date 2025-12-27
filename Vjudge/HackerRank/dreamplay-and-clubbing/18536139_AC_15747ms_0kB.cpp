#include <bits/stdc++.h>

using namespace std;
long long DP[270][4600][2][2];
long long MOD=1e9+7;
string n;
long long solve(int idx,int sum,bool xlessy,bool ylessin)
{
    if(idx==0)
        return (long long)((sum-2250)>0);
    long long &ret=DP[idx][sum][xlessy][ylessin];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int ydig=(ylessin?9:(n[n.size()-idx]-'0'));ydig>=0;ydig--)
        for(int xdig=(xlessy?9:ydig);xdig>=0;xdig--){
            ret+=solve(idx-1,sum+ydig-xdig,xlessy|(xdig<ydig),ylessin|(ydig<n[n.size()-idx]-'0'));
            ret%=MOD;
    }
    return ret;

}
int main()
{
    memset(DP,-1,sizeof DP);
    cin>>n;
    cout<<solve(n.size(),2250,0,0)<<endl;
    return 0;
}