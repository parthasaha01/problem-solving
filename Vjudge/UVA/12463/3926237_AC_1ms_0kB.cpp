#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,res;

    while(cin >> a >> b >> c >> d >> e)
    {
        if(a==0 && b==0 && c==0 && d==0 && e==0)
            break;
        res = a*b*c*(d*d)*(e*e);

        cout << res << endl;
    }

    return 0;
}
