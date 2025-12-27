#include<bits/stdc++.h>
using namespace std;
int bigmod(int b,int p)
{
    int res=1;
    if(p==1) return b%10;

    if(p%2==0){
        res = bigmod(b,p/2)%10;
        res = ((res%10)*(res%10))%10;
    }
    else{
        res = ((bigmod(b,p-1)%10)*(b%10)%10);
    }
    return res%10;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) cout << "1" << endl;
        else if(n==1) cout << "8" << endl;
        else cout << bigmod(1378,n) << endl;
    }

    return 0;
}

