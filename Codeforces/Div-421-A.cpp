#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,v0,v1,a,l;
    while(cin>>c>>v0>>v1>>a>>l)
    {


        int ans=0;

        int p;
        p=v0;
        ans++;
        int i=1;
        int s=v0;

        while(s<c)
        {
            int k = v0+(i*a);
            if(k>v1)k=v1;
            k -= l;
            s += k;
            ans++;
            i++;
        }

        cout << ans << endl;

    }

    return 0;
}
