#include<bits/stdc++.h>
using namespace std;
long numberOfDivisors(long n)
{
    long res=1,cnt,i;

    if(n%2==0)
    {
        cnt=0;
        while(n%2==0)
        {
            cnt++;
            n=n/2;
        }
        res=res*(cnt+1);
    }

    for(int i=3; i<=sqrt(n); i+=2)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            res=res*(cnt+1);
        }
    }

    if(n>1)
        res=res*2;

    return res;
}
int main()
{
    long a,b,res,s;

    while(cin >> a >> b)
    {
        if(a==0 && b==0)
            break;
        s=abs(a-b);

        res=numberOfDivisors(s);
        cout << res << endl;
    }

    return 0;
}
