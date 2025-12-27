#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long

int main()
{
    int n;
    while(cin>>n)
    {
        if(n>1)
        {
            int a = n;
            int b = n+1;
            int c = n*(n+1);
            cout << a << " " << b << " " << c << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }

    return 0;
}

