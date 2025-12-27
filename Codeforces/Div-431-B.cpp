#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[1005],my[1005][1005],mx[1005][1005];
map<pair<int,int>,int>mp;
int main()
{
    scanf("%I64d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>j)my[i][j] = a[i]-a[j];
            else my[i][j] = a[j]-a[i];

            if(i>j)mx[i][j] = i-j;
            else mx[i][j] = j-i;
        }


    }


}
