#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[5];
int main()
{
    ll b,d,s;

    while(cin>>b>>d>>s)
    {
        ll ans=0;
        if((b==d&&d==s)||(b+d+s==1)){
            ans=0;
        }
        else
        {
            a[0]=b;
            a[1]=d;
            a[2]=s;
            sort(a,a+3);

            if(a[2]!=a[1]){
                ans+=a[2]-a[1]-1;
            }
            if(a[2]!=a[0]){
                ans+=a[2]-a[0]-1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
