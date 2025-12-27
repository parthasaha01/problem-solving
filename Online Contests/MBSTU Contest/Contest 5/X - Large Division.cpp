#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    long int t,b;
    cin >> t;

    for(int kase=1; kase<=t; kase++)
    {
        cin >> a >> b;

        int sz=a.size();

        if(b<0)
            b=-b;

        int start=0;

        if(a[0]=='-'){
            start=1;
        }

        long int n=0;
        long int rem;

        for(int i=start; i<sz; i++)
        {
            n += a[i]-'0';
            rem = n%b;
            n = rem*10;
        }

        if(rem==0)
            printf("Case %d: divisible\n",kase);
        else
            printf("Case %d: not divisible\n", kase);
    }

    return 0;
}
