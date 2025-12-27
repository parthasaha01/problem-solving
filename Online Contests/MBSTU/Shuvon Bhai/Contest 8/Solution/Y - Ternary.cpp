#include<bits/stdc++.h>
using namespace std;
void Ternary(long n)
{
    if(n==0)
        return ;
    Ternary(n/3);
    cout << n%3;
}
int main()
{
    long N;

    while(cin >> N && N>=0)
    {
        if(N==0){
            cout << "0" << endl;
            continue;
        }
        Ternary(N);
        cout << endl;
    }

    return 0;
}
