#include<bits/stdc++.h>
using namespace std;
#define LLI long long int
int len,mid;
bool odd;
char s[20];
LLI dp[20][2][2];
int a[25];
LLI Palindrome(int pos,int choto,int flag)
{
    if(pos==len-1)
    {
        return 1;
    }
    int next_choto,next_flag,num;
    int low=0,high=9;
    LLI ret=0;
    if(choto==0)
    {
        high=s[pos]-'0';
    }
    if(pos<mid)
    {
        int j=0;
        for(int i=low; i<=high; i++)
        {
            if(choto==0)
            {
                if(i==high)
                    next_choto=0;
                else
                    next_choto=1;
            }
            else
                next_choto=1;

            next_flag=flag;
            if(i>0)
            {
                next_flag=1;
            }
            if(next_flag)
            {
                a[j]=i;
                j++;
            }
            ret+=Palindrome(pos+1,next_choto,next_flag);
        }
    }
    else
    {
        if(odd)
        {
            num=a[2*mid-pos];
            if(num<=s[pos])
            {
                next_choto=0;
                next_flag=flag;
                ret+=Palindrome(pos+1,next_choto,next_flag);
            }
        }
        else
        {
            if(num<=s[pos])
            {
                next_choto=0;
                next_flag=flag;
                ret+=Palindrome(pos+1,next_choto,next_flag);
            }
        }

    }

    return dp[pos][choto][flag]=ret;
}
int main()
{
    int T;
    LLI res,cnt1,cnt2,L1,L2;
    scanf("%d",&T);
    for(int test=1; test<=T; test++)
    {
        scanf("%lld %lld",&L1,&L2);

        if(L1>L2)
            swap(L1,L2);

        if(!L1&&!L2)
            res=0;
        else
        {
            if(!L1)
                cnt1=0;
            else
            {
                sprintf(s,"%lld",L1-1);
                len=strlen(s);
                memset(dp,-1,sizeof(dp));
                if((L1-1)&1)
                {
                    odd=true;
                    mid=len/2;
                }
                else
                {
                    odd=false;
                    mid=(len/2)-1;
                }
                cnt1=Palindrome(0,0,0);
            }

            sprintf(s,"%lld",L2);
            len=strlen(s);
            memset(dp,-1,sizeof(dp));
        if(L2&1)
        {
            odd=true;
            mid=len/2;
        }
        else
        {
            odd=false;
            mid=(len/2)-1;
            }
            cnt2=Palindrome(0,0,0);

                 res=abs(cnt2-cnt1);
        }

        printf("Case %d: %lld\n",test,res);

    }

    return 0;

}
