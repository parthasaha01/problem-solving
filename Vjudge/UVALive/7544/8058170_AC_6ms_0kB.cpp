#include<bits/stdc++.h>
using namespace std;
#define inf -100000000
//string pn,pin;
//string ss;
char pn[500],pin[500],ss[500];
int sum[500],sz,pz;
int dp[500][500];
void calculate()
{
    sum[0]=0;
    for(int i=1; i<strlen(pin); i++){
        sum[i] = sum[i-1] + (pin[i]-'0');
    }
}
int getsum(int l, int r)
{
    if(r>=pz)return inf;
    return sum[r]-sum[l-1];
}
int fun(int no,int pos)
{
    if(no>=sz || pos>=pz){
        return 0;
    }

    if(dp[no][pos] != -1)return dp[no][pos];

    int ret1=0,ret2=0;
    int ln = ss[no]-'a';

    if(pos+ln<pz)
        ret1 = getsum(pos,pos+ln) + fun(no+1,pos+ln+1);
    ret2 = fun(no,pos+1);

    return dp[no][pos] = max(ret1,ret2);
}
int main()
{
    while(gets(pn))
    {
        gets(ss);

        strcpy(pin,"0");
        strcat(pin,pn);

        pz = strlen(pin);
        sz = strlen(ss);

        //puts(pin);
        //puts(ss);

        calculate();

        memset(dp,-1,sizeof(dp));

        int ans = fun(0,1);
        printf("%d\n",ans);
    }

    return 0;
}
