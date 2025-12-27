#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
ll n,k;
ll c[mx],kv[mx],cv[mx];
int main()
{
    ll total=0;
    scanf("%I64d%I64d",&n,&k);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&c[i]);
        total += c[i];
    }
    for(int i=1; i<=k; i++)
    {
        scanf("%I64d",&kv[i]);
    }

    ll sum=0;
    ll cc=c[1]*c[n];
    sum += cc;
    cv[1]+= cc;
    cv[n]+= cc;
    for(int i=1; i<n; i++)
    {
        ll cc=c[i]*c[i+1];
        sum += cc;
        cv[i]+= cc;
        cv[i+1]+= cc;
    }
    /*cout << total << " " << sum << endl;
    for(int i=1; i<=n; i++)
    {
        cout << i << "-" << cv[i] << endl;
    }*/
    ll sum1=0;
    for(int i=1; i<=k; i++)
    {
        ll cur=kv[i];
        sum += (c[cur]*(total-c[cur]));
        //cout << "sum-" << sum << endl;
        sum -= cv[cur];
        //cout << "sum-" << sum << endl;
        if(kv[i]-1 != kv[i-1])
        {
            sum -= c[cur]*sum1;
        }
        else
        {
            sum -= c[cur]*(sum1-c[cur-1]);
        }

        if(kv[i]==n)
        {
            if(kv[1]==1){
                sum+=c[n]*c[1];
            }
        }

        sum1+=c[cur];
        //cout << "sum-" << sum << " sum1-" << sum1 << endl;
    }

    printf("%I64d",sum);

    return 0;
}
/*
5 2
3 5 2 2 4
1 4
3 3
1 1 1
1 2 3
*/
