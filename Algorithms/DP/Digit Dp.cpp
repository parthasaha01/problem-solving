#include<bits/stdc++.h>
using namespace std;
int dp[20][20][2][2];
int len;
string N;
int DigitDP(int pos,int zero,int choto,int start)
{
    int ret,next_zero,next_choto,next_start;
    ret=next_zero=next_choto=next_start=0;

    if(pos==len){
        return zero;
    }
    if(dp[pos][zero][choto][start] != -1){
            cout << "dp" << endl;
        return dp[pos][zero][choto][start];
    }
    int low=0,high=9;
    if(choto==0){   //soman
        high=N[pos]-'0';
    }
    for(int i=low; i<=high; i++)
    {
        if(choto==1){
            next_choto=1;
        }
        else{
            if(i<high){
                next_choto=1;
            }
            else{
                next_choto=0;
            }
        }

        next_start=start;
        if(i!=0){
            next_start=1;
        }
        next_zero=zero;
        if(start==1 && i==0)
        {
            next_zero=zero+1;
        }

        cout << "i=" << i << "  " << pos+1 << " " << next_choto << " " << next_start << " " << next_zero << endl;
        ret += DigitDP(pos+1,next_zero,next_choto,next_start);
        cout << endl;
    }
    return dp[pos][zero][choto][start]=ret;
}
int main()
{
    int T,cnt;
    cin >> T;

    while(T--)
    {
        cin >> N;
        len=N.size();
        memset(dp,-1,sizeof(dp));
        cnt=DigitDP(0,0,0,0); //
        cout << cnt << endl;
    }

    return 0;
}
