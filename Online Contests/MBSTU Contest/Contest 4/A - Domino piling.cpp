#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,res;

    while(cin >> m >> n)
    {
        if(m==1 && n==1){
            res=0;
        }
        else if(m%2==0 || n%2==0){
            res = (m*n)/2;
        }
        else{
            if(m>n){
                swap(m,n);
            }

            res = ((n-1)*m)/2 + (m/2);
        }

        cout << res << endl;
    }

    return 0;
}
