#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    long int T,N,i,prev,flag;

    cin >> T;

    while(T--)
    {
        string str = "";
        flag=1;
        cin >> N;

        while(N>=10)
        {
            prev=N;

            for(i=9;i>=2;i--)
            {
                if((N%i) == 0)
                {
                    str += (i+'0');
                    N=N/i;
                    break;
                }
            }
            if(prev==N)
            {
                flag=0;
                break;
            }
        }
        str += (N+'0');

        sort(str.begin(), str.end());

        if(flag==0)
            cout << "-1" << endl;
        else
            cout << str << endl;
    }

    return 0;

}
