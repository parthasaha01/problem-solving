#include<bits/stdc++.h>
using namespace std;
int a[9];
int main()
{
    int i,flag;

    while(cin >> a[8])
    {
        for(i=7; i>=0; i--)
            cin >> a[i];

        /*for(i=8; i>=0; i--)
            cout << a[i] << " ";
        cout << endl;*/

        flag=0;

        for(i=8; i>=2; i--)
        {
            if(a[i]==0)
                continue;
            else if(a[i]>0)
            {
                if(flag==1)
                    cout << " + ";

                if(a[i]==1)
                    cout << "x^" << i;
                else
                    cout << a[i] << "x^" << i;
                flag=1;
            }
            else
            {
                a[i]=-a[i];
                if(flag==1)
                    cout << " - ";
                else
                    cout << "-";

                if(a[i]==1)
                    cout << "x^" << i;
                else
                    cout << a[i] << "x^" << i;

                flag=1;
            }
        }

        if(a[1]!=0)
        {
            if(a[i]>0)
            {
                if(flag==1)
                    cout << " + ";

                if(a[i]==1)
                    cout << "x";
                else
                    cout << a[1] << "x";
            }
            else
            {
                a[1]=-a[1];

                if(flag==1)
                    cout << " - ";
                else
                    cout << "-";

                if(a[i]==1)
                    cout << "x";
                else
                    cout << a[1] << "x";
            }
            flag=1;
        }

        if(a[0]!=0)
        {
            if(a[0]>0)
            {
                if(flag==1)
                    cout << " + " << a[0];
                else
                    cout << a[0];
            }
            else
            {
                a[0]=-a[0];
                if(flag==1)
                    cout << " - " << a[0];
                else
                    cout << "-" << a[0];
            }
            flag=1;
        }

        if(flag==0)
            cout << "0";

        cout << endl;
    }

    return 0;
}
