#include<bits/stdc++.h>
using namespace std;
long int a[10005];
long int rem[5];
int main()
{
    long int n,r,res,val;

    while(cin >> n)
    {
        memset(rem,0,sizeof(rem));

        for(int i=0; i<n; i++){
            cin >> val;
            r=val%3;
            rem[r]++;
        }

        res = rem[0]/2;
        if(rem[1]<rem[2]){
            res += rem[1];
        }
        else{
            res += rem[2];
        }

        cout << res << endl;
    }

    return 0;
}
