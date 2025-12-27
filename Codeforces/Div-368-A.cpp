#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;

    while(cin >> n >> m)
    {
        bool flag=false;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                char ch;
                cin >> ch;
                //cout << ch << "*";
                if(ch=='C' || ch=='M' || ch=='Y' || ch=='c' || ch=='m' || ch=='y')
                {
                    flag=true;
                }
            }
        }

        if(flag==false)
        {
            cout << "#Black&White" << endl;
        }
        else
        {
            cout << "#Color" << endl;
        }
    }

    return 0;
}
