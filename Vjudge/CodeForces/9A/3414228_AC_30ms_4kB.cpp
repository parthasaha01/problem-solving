#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
    return b==0 ? a : GCD(b,a%b);
}
int main()
{
    int Y,W,gcd,Mx,lob;

    while(cin >> Y >> W)
    {
        Mx=max(Y,W);
        lob=6-Mx+1;
        gcd=GCD(lob,6);
        cout << lob/gcd << "/" << 6/gcd << endl;
    }

    return 0;
}
