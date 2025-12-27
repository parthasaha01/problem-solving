#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n,m,res;

    while(cin >> n >> m)
    {

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        sort(a,a+n);
        res=0;
        for(int i=0; i<m; i++)
        {
            if(a[i]<0)
                res += a[i];
        }

        res = (-1)*res;


        cout << res << endl;
    }

    return 0;
}
