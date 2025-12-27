#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t,n,s,row,col,b,e,m;
    double sq;
    cin >> t;

    for(int kase=1; kase<=t; kase++)
    {
        cin >> s;

        sq= sqrt((double)s);

        if(sq==(ll)sq){
            n=sq;
        }
        else{
            n=sq+1;
        }

        b=((n-1)*(n-1))+1;
        e=n*n;
        m=(b+e)/2;

        //cout << n << " " << b << " " << e << " " << m << endl;

        col=row=n;
        if(s>m){
            row = (e-s)+1;
        }
        else{
            col = (s-b)+1;
        }

        if(n%2==1){
            swap(col,row);
        }

        cout << "Case " << kase << ": " << col << " " << row << endl;
    }

    return 0;
}
