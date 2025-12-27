#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[10005],sum[10005];
int main()
{
    sum[0]=0;
    cnt[0]=0;
    for(int n=1; n<=10000; n++)
    {
        int sq = sqrt(n);
        int kk=0;
        for(int d=1; d<=sq; d++)
        {
            if(n%d==0)
            {
                kk++;
            }

        }
        cnt[n]=kk;
        sum[n]=sum[n-1]+cnt[n];
    }

    int v;
    while(cin>>v)
    {
        cout << sum[v] << endl;
    }


    return 0;
}
