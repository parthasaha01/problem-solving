#include<bits/stdc++.h>
using namespace std;
int F[1005];
int fib()
{
    int a=1,b=1,n;
    while(n<=1000)
    {
        n=a+b;
        F[n]=1;
        a=b;
        b=n;
    }
}
int main()
{
    fib();
    int n;
    while(cin >> n && n)
    {
        if(F[n]==1)
            cout << "Roberto" << endl;
        else
            cout << "Alicia" << endl;
    }

    return 0;
}
