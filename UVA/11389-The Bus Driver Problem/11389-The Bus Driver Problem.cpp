#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long long n, d, r, i, k, pay, mor[100], eve[100], len;

    while(scanf("%lld %lld %lld", &n, &d, &r))
    {
        if(!n && !d && !r)
            break;

        for(i=0; i<n; i++)
            scanf("%lld", &mor[i]);

        for(i=0; i<n; i++)
            scanf("%lld", &eve[i]);

        sort(mor, mor+n);
        sort(eve, eve+n);

        i=0;
        k=n-1;
        pay=0;

        while(i<n)
        {
            len= (mor[i++] + eve[k--]);

            if(len>d)
            {
                pay += (len-d);
            }
        }

        pay *= r;

        printf("%lld\n", pay);
    }

    return 0;
}
