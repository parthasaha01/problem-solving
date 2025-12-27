
#include<bits/stdc++.h>
using namespace std;
# define ll long long int
int st[1000009];
int main()
{
    ll p;
    cin>>p;
    memset(st,-1,sizeof(st));
    for(ll i=0;i<p;i++)
    {
        st[(i*i)%p]=i;
    }
    cout<<st[0];
    for(int i=1;i<p;i++)
        cout<<" "<<st[i];
        cout<<endl;
}