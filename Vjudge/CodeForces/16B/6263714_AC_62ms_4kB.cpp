#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct type{
    ll box,match;
}a[25];
bool cmp(type x, type y)
{
    return x.match > y.match;
}
int main()
{
    ll n,m;
    while(cin >> n >> m)
    {
        for(int i=0; i<m; i++)
        {
            cin >> a[i].box >> a[i].match;
        }

        sort(a,a+m,cmp);

        ll total=0;
        //ll cnt=0;
        ll need=n;
        for(int i=0; i<m; i++)
        {
            if(a[i].box<=need)
            {
                total += a[i].box*a[i].match;
                need -= a[i].box;
            }
            else
            {
                total += need*a[i].match;
                need=0;
                break;
            }
        }

        cout << total << endl;
    }

    return 0;
}
