#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,res;
    cin >> t;

    for(int kase=1; kase<=t; kase++)
    {
        cin >> a >> b;

        if(a<=b){
            res = (b*4) + 19;
        }
        else{
            res = 4*(a-b) + (4*a) + 19;
        }

        cout << "Case " << kase << ": " << res << endl;
    }

    return 0;
}
