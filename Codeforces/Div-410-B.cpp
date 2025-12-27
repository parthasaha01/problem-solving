#include<bits/stdc++.h>
using namespace std;
#define mx 10000000
string s[55];
int n,fr[30],tr[30],sz;
bool Ispossible()
{
    memset(fr,0,sizeof(fr));

    for(int j=0; j<s[1].size(); j++){
        int ch = s[1][j]-'a';
        fr[ch]++;
    }

    for(int i=1; i<=n; i++)
    {
        memset(tr,0,sizeof(tr));
        for(int j=0; j<s[i].size(); j++)
        {
            int ch = s[i][j]-'a';
            tr[ch]++;
        }

        for(int k=0; k<26; k++){
            if(fr[k]!=tr[k]){
                return false;
            }
        }
    }

    return true;
}
string fun(string ts)
{
    string tt;

    for(int i=1; i<sz; i++){
        tt+=ts[i];
    }
    tt+=ts[0];

    return tt;
}
int calculate(string tt)
{
    int sum=0;

    for(int i=1; i<=n; i++)
    {
        string ss = s[i];
        //bool flag = false;
        int cnt=mx;
        for(int k=0; k<sz; k++)
        {
            string xx;
            if(k==0){
                xx = ss;
            }
            else{
                xx = fun(ss);
            }

            //cout << "i=" << i << " xx=" << xx << " " << "tt=" << tt << endl;

            if(xx==tt){
                cnt=k;
                break;
            }
            ss = xx;
        }

        sum+=cnt;
    }

    return sum;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            cin>>s[i];
        }

        if(n==1){
            printf("0\n");
            continue;
        }

        int flag = Ispossible();

        if(flag==false)
        {
            printf("-1\n");
            continue;
        }

        string ts = s[1];

        sz = s[1].size();

        int ans = mx;

        for(int k=0; k<sz; k++)
        {
            string tt;

            if(k==0){
                tt = ts;
            }
            else{
                tt = fun(ts);
            }

            //cout << tt << endl;

            int val = calculate(tt);

            ans = min(val,ans);

            ts = tt;
        }

        if(ans>=mx){
            printf("-1\n");
        }
        else{
            printf("%d\n",ans);
        }
    }

    return 0;
}
