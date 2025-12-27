#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        char s[15];
        cin>>s;

        ll p=strlen(s);
        ll n=atoll(s);

        ll sum=0;

        for(int i=0; i<p; i++)
        {
            ll dg=s[i]-'0';
            ll cnt=1;
            for(int j=1; j<=p; j++)
            {
                cnt*=dg;
            }
            sum+=cnt;
        }

        if(n==sum)
            printf("Armstrong\n");
        else
            printf("Not Armstrong\n");
    }

    return 0;
}
