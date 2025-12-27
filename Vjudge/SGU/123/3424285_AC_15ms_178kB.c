#include<bits/stdc++.h>
using namespace std;
long fib[50]={1,1,1};
long sum[50]={0,1,2};
void fibonacci(int n)
{
    if(n==42)
        return;
    fib[n]=fib[n-1]+fib[n-2];
    sum[n]=sum[n-1]+fib[n];
    fibonacci(n+1);
}
int main()
{
    fibonacci(3);
    int k;
    while(cin >> k)
    {
        cout << sum[k] << endl;
    }

    return 0;
}
