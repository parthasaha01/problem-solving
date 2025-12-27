#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,a,b,x,y;
    cin>>n>>a>>b;

    bool flag = false;

    for(ll i=0; (i*a)<=n; i++)
    {
        ll cst = (i*a);
        ll rem = n-cst;
        if(rem%b==0){
            x = i;
            y = rem/b;
            flag = true;
            break;
        }
    }

    if(flag==true){
        printf("YES\n");
        cout << x << " " << y << endl;
    }
    else printf("NO\n");

    return 0;
}
