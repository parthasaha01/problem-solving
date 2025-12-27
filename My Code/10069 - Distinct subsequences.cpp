#include<bits/stdc++.h>
using namespace std;
int n,m;
string dp[10005][105];
string a,b;
int check(string x,string y)
{
    if(x.size()==y.size())
    {
        if(x==y) return 1;
        if(x>y) return 2;
        if(x<y) return 3;
    }

    if(x.size()>y.size())return 2;
    if(x.size()<y.size())return 3;
}
string summation(string x, string y)
{

    int flag = check(x,y);
    if(flag==3)swap(x,y);

    string z;

    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());

    int p,q,s,ci=0,k;
    for(k=0; k<y.size(); k++)
    {
        p = x[k]-'0';
        q = y[k]-'0';
        s = p+q+ci;
        ci = s/10;
        s = s%10;
        z += s+'0';
    }

    for( ; k<x.size(); k++)
    {
        p = x[k]-'0';
        s = p+ci;
        ci = s/10;
        s = s%10;
        z += s+'0';
    }

    if(ci>0)z += ci+'0';

    reverse(z.begin(),z.end());

    return z;
}
string fun(int i,int j)
{
    if(j==m)return "1";
    if(i==n)return "0";

    if(dp[i][j]!="-1")return dp[i][j];

    string ret="0";

    if(a[i]==b[j]){
        string p = fun(i+1,j+1);
        ret = summation(ret,p);
    }

    string q = fun(i+1,j);
    ret = summation(ret,q);

    return dp[i][j]=ret;
}

int main()
{
    int tt; scanf("%d",&tt);

    while(tt--)
    {
        cin>>a>>b;
        n = a.size();
        m = b.size();

        for(int i=0; i<=n; i++){
            for(int j=0;j<=m;j++){
                dp[i][j]="-1";
            }
        }

        string lcs = fun(0,0);
        cout << lcs << endl;
    }
    return 0;
}

