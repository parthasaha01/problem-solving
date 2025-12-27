#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char ar[5][5]= {"16","06","68","88"};
    //for( int i=1; i<=109; i++ ) cout<<i<<" ";

    while(cin>>n)
    {
        if( n > 4 ) cout<<"Glupenky Pierre"<<endl;
        else
        {
            cout<<ar[0];
            for(int i=1; i<n; i++ ) cout<<" "<<ar[i];
            cout<<endl;
        }
    }
    return 0;
}
