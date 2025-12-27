#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int main()
{
    int n, k; cin>>n>>k;

    for(int i=1; i<=k; i++)
    {
        int r = n%10;
        if(r==0){
            n/=10;
        }
        else{
            n--;
        }
    }

    cout << n << endl;

    //main();

    return 0;
}
