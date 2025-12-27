#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,x,y;

    cin >> t;

    for(int kase=1; kase<=t; kase++)
    {
        cin >> a;
        x=0;
        y=a;
        if(a>10){
            x=a-10;
            y=a-x;
        }

        cout << x << " " << y << endl;
    }

    return 0;
}

