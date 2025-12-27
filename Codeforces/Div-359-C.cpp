#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,res,num,cnt1,cnt2;

    while(cin >> n >> m)
    {
        num=n;
        cnt1=0;
        while(num!=0)
        {
            ++cnt1;
            num /= 7;
        }

        num=m;
        cnt2=0;
        while(num!=0)
        {
            ++cnt2;
            num /= 7;
        }

        printf("%ld %ld\n",cnt1, cnt2);

        cout << res << endl;
    }

    return 0;
}
