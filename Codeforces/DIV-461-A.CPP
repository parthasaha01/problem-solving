#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int main()
{
    // ios::sync_with_stdio(false); cin.tie(0);

    ll x,y;
    cin>>x>>y;

    if(y==0){
        printf("NO\n");
        return 0;
    }

    if(y==1 && x==0){
        printf("YES\n");
        return 0;
    }

    if(y==1 && x>0){
        printf("NO\n");
        return 0;
    }

    ll org = 0;
    ll cop = 0;

    org = y;
    cop = y-1;

    ll rem = x-cop;

    if(rem<0){
        printf("NO\n");
        return 0;
    }

    if(rem%2==0){
        printf("YES\n");
        return 0;
    }
    else{
        printf("NO\n");
        return 0;
    }

    return 0;
}
