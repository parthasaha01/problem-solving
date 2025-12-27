#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long num1,num2,n1,n2,n,m,bx,by,i,j,k,po,digit;

    cin >> n >> bx;
    num1=0;
    for(i=n-1; i>=0; i--)
    {
        cin >> digit;
        n1=1;
        for(j=1; j<=i; j++){
            n1*=bx;
        }

        num1+= digit*n1;
    }
    cin >> m >> by;
    num2=0;
    for(i=m-1; i>=0; i--)
    {
        cin >> digit;
        n2=1;
        for(j=1; j<=i; j++){
            n2*=by;
        }
        num2+= digit*n2;
    }
    //cout << num1 << " " << num2 << endl;
    if(num1==num2)
        cout << "=" << endl;
    else if(num1>num2)
        cout << ">" << endl;
    else
        cout << "<" << endl;

    return 0;
}
