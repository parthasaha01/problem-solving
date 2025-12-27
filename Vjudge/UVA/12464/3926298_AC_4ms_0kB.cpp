#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,n,res,rem;

    while(cin >> a >> b >> n)
    {
        if(a==0 && b==0 && n==0)
            break;

        rem=n%5;

        if(rem==0)
        {
            res=a;
        }
        else if(rem==1)
        {
            res=b;
        }
        else if(rem==2)
        {
            res=(b+1)/a;
        }
        else if(rem==3)
        {
            res=((a+b+1)/a)/b;
        }
        else
        {
            res=(a+1)/b;
        }

        cout << res << endl;
    }

    return 0;
}
