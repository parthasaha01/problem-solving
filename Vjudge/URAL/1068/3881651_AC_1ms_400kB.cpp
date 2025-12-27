#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long N,sum,flag;

    while(cin >> N)
    {
        sum=0;

        if(N<=0){
            flag=1;
            N=-N;
        }
        else
            flag=0;

        sum=(N*(N+1))/2;

        if(flag==0)
            cout << sum << endl;
        else
            cout << -1*sum+1 << endl;
    }
    return 0;
}
