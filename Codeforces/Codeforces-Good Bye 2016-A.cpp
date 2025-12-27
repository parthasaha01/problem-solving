#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        int d = 240-k;
        int cnt = 0;
        int p = 5;
        int b = 5;
        while(p<=d)
        {
            b += 5;
            p += b;
            cnt++;
        }

        printf("%d\n",min(cnt,n));
    }
    return 0;
}
