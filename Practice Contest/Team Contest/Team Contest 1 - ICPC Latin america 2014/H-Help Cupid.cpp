#include<bits/stdc++.h>
using namespace std;
#define inf 100000;
vector<int>v;
map<int,int>mp;
map<int, map<int,int> > dp;
map<int, map<int,int> > vs;
int n,sz,arr[1012];
int fun(int pos,int mask)
{
    if(pos==sz)return 0;

    if(vs[pos][mask]!=0)return dp[pos][mask];
    vs[pos][mask]=1;

    int ret,ret1,ret2;
    ret1=ret2=0;

    if((mask&(1<<pos))==0)
    {
        if(pos==0){

            int cost = abs(v[pos]-v[pos+1]);
            cost = min(cost,24-cost);
            int nmask = mask;
            nmask = (nmask|(1<<pos));
            nmask = (nmask|(1<<(pos+1)));
            ret1 = cost + fun(pos+1,nmask);

            cost = abs(v[pos]-v[sz-1]);
            cost = min(cost,24-cost);
            nmask = mask;
            nmask = (nmask|(1<<pos));
            nmask = (nmask|(1<<(sz-1)));
            ret2 = cost + fun(pos+1,nmask);

            ret = min(ret1,ret2);
        }
        else if(pos==sz-1){
            //
        }
        else{
            int cost = abs(v[pos]-v[pos+1]);
            cost = min(cost,24-cost);
            int nmask = mask;
            nmask = (nmask|(1<<pos));
            nmask = (nmask|(1<<(pos+1)));
            ret = cost + fun(pos+1,nmask);
        }
    }
    else
    {
        ret = fun(pos+1,mask);
    }

    return dp[pos][mask]=ret;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        mp.clear();
        v.clear();
        dp.clear();
        vs.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            mp[arr[i]]++;
        }



        for(int i=-11;i<=12;i++)
        {
            if(mp[i]%2==1)
                v.push_back(i);
        }

//        for(int i=0;i<v.size();i++)
//        {
//            cout<<v[i]<<" ";
//        }

        sort(v.begin(),v.end());
        sz = v.size();


        int ans = fun(0,0);

        printf("%d\n",ans);
    }

    return 0;
}
