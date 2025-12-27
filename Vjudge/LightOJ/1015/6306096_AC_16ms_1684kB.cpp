#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,v,s;

    cin >> t;

    for(int kase=1; kase<=t; kase++)
    {
        cin >> n;
        s=0;
        for(int i=0; i<n; i++){
            cin >> v;

            if(v>0){
                s+=v;
            }
        }

        cout << "Case " << kase << ": " << s << endl;
    }

    return 0;
}
