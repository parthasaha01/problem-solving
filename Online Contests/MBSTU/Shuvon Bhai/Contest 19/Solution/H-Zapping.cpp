#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, press;

    while(cin >> a >> b)
    {
        if(a == -1 && b == -1)
            break;

        press = b-a;

        if(press < 0)
            press = -press;

        if(press > 50)
            press = 100-press;

        cout << press << endl;
    }


    return 0;
}

