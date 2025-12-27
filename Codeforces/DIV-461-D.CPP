#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dt
{
    ll x,y,z;
}st[100003];
string s;

bool cmp(dt a,dt b)
{
    ll p = a.x*b.y;
    ll q = a.y*b.x;

    if(p>q)return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;

    for(int i=1; i<=n; i++)
    {
        //getchar();
        //scanf("%s",s);
        cin>>s;
        //printf("%s\n",s);
        int sz = s.size();

        ll cs=0,ch=0,cz=0;

        for(int k=0; k<sz; k++)
        {
            if(s[k]=='s')cs++;
            else{
                ch++;
                cz+=cs;
            }
        }

        st[i].x = cs;
        st[i].y = ch;
        st[i].z = cz;
    }

    sort(st+1,st+n+1,cmp);

    ll ans = 0;

    ll cs = 0;
    ll ch = 0;
    for(int i=1; i<=n; i++)
    {
        ll x,y,z;
        x = st[i].x;
        y = st[i].y;
        z = st[i].z;

        ans += cs*y;
        ans += z;
        cs += x;
    }

    //printf("%I64d\n",ans);
    cout << ans << endl;

    return 0;
}
