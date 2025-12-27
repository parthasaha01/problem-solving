#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;

    if((n%2)==0 || (m%2)==1)
        cout << "yes";
    else
        cout << "no";

    return 0;
}
