#include<bits/stdc++.h>
using namespace std;
long int d[15],f[15];
int main()
{
    long int t,n;
    cin >> t;

    d[0]=1;
    d[1]=0;
    f[0]=1;
    f[1]=1;

    for(int i=2; i<15; i++){
        d[i] = (i-1)*(d[i-1]+d[i-2]);
        f[i] = f[i-1]*i;
    }

    while(t--)
    {
        cin >> n;

        cout << d[n] << "/" << f[n] << endl;
    }

    return 0;
}
