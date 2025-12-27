#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,Max,sum,half,hi;

    while(cin >> n && n)
    {
        long a[n];

        if(n&1)
            half=(n/2)+1;
        else
            half=n/2;

        a[0]=0;
        a[1]=1;
        Max=1;

        for(long i=2; i<=half; i++)
        {
            hi=i/2;

            if(i&1)
                a[i]=a[hi]+a[hi+1];
            else
                a[i]=a[hi];

            sum=a[i]+a[i-1];
            if(sum>Max)
                Max=sum;
        }

        cout << Max << endl;
    }

    return 0;
}
