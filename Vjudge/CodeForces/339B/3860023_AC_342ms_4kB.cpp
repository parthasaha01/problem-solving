#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n,m;

    while(cin>>n>>m)
    {
        long cur=1;
        long des;
        long long ans=0;
        for(int i=0; i<m; i++)
        {
            cin >> des;
            if(cur>des)
            {
                ans+=((n-cur)+des);
                cur=des;
            }
            else
            {
                ans+=(des-cur);
                cur=des;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
