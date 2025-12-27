#include<bits/stdc++.h>
using namespace std;
long trailingZero(long N)
{
    long i,cnt=0;
    for(i=5; i<=N; i*=5)
    {
        cnt+=(N/i);
    }

    return cnt;
}
int main()
{
    long T,N,cnt;
    cin >> T;

    while(T--)
    {
        cin >> N;
        cnt=trailingZero(N);
        cout << cnt << endl;
    }

    return 0;
}
