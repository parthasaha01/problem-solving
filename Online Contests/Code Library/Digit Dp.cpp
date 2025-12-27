#include<bits/stdc++.h>
using namespace std;
long long dp[12][2][2][25],len;
char s[12];
long long call(int pos, int choto, int flag,long long zero)
{
    if(pos==len)
        return zero;

    if(dp[pos][choto][flag][zero]!=-1)
        return dp[pos][choto][flag][zero];

    long long ret=0;

    int  low=0,high=9;
    if(choto==0)
        high=s[pos]-'0';

    for(int i=low; i<=high; i++){
        /*int next_flag=flag;
        if(i>0)
            next_flag=1;*/
       /*int next_choto;
        if(choto==0)
        {
            if(i==high)
                next_choto=0;
            else
                next_choto=1;
        }
        else
            next_choto=1;*/

        ret += call(pos+1,choto||(i<(s[pos]-'a')),/*next_choto*/flag||i,zero+(i==0&&flag));
    }

    return dp[pos][choto][flag][zero]=ret;
}
int main()
{
    int T,test;
    long long cnt1,cnt2,n,m,res;

    cin >> T;

    for(test=1; test<=T; test++)
    {
        cin >> m >> n;

        if(m==0 && n==0){
            res=1;
        }
        else
        {
            if(m!=0)
            {
                sprintf(s,"%lld",m-1);
                len=strlen(s);
                memset(dp,-1,sizeof(dp));

                cnt1 = call(0,0,0,0);
            }
            else
                cnt1=-1;

            sprintf(s,"%lld",n);
            len=strlen(s);
            memset(dp,-1,sizeof(dp));

            cnt2 = call(0,0,0,0);

            res=abs(cnt2-cnt1);
        }

        printf("Case %d: %lld\n",test,res);
    }

    return 0;
}

