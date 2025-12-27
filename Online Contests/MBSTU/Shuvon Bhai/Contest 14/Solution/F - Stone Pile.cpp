#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    while(cin >> n)
    {
        long w[n],sum=0;

        for(int i=0; i<n; i++)
        {
            cin >> w[i];
            sum+=w[i];

        }
        long mid=sum/2;
        sort(w,w+n);

        if(n==1){
            cout << w[0] << endl;
            continue;
        }


        long sum1=0,sum2=0,Min,j;

        sum1=w[n-1];
        sum2=w[n-2];
        for(int i=n-3; i>=0; i--)
        {
            if(sum1+sum2<=mid)
            {
                sum2=sum1+sum2;
                sum1=w[i];
            }
            else if(sum1<sum2)
            {
                sum1+=w[i];
            }
            else
            {
                sum2+=w[i];
            }
        }

        if(sum1<sum2)
            cout << sum2-sum1 << endl;
        else
            cout << sum1-sum1 << endl;
    }

    return 0;
}
