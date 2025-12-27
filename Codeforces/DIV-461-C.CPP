#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[10000009];
int main()
{
    ll n,k;
    scanf("%I64d %I64d",&n,&k);

    //if(n==1 && k==1){
       // printf("Yes\n");
        //return 0;
    //}

    //if(k>=n){
       // printf("No\n");
    //}
    //else
    //{
        bool flag = true;
        for(ll i=1; i<=k && i<=10000007; i++)
        {
            ll r = n%i;
            if(vis[r]==true){
                flag = false;
                break;
            }
            vis[r]=true;
        }

        if(flag)printf("Yes\n");
        else printf("No\n");
    //}

    return 0;
}
