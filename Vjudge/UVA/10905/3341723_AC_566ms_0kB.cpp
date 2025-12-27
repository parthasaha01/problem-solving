#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int N,i,j;

    while(cin >> N && N)
    {
        string str[N], temp, temp1, temp2;

        for(i=0; i<N; i++)
        {
            cin >> str[i];
        }

        for(i=0; i<N-1; i++)
        {
            for(j=0; j<N-1-i; j++)
            {
                temp1=str[j]+str[j+1];
                temp2=str[j+1]+str[j];

                if(temp1>temp2)
                {
                    temp=str[j];
                    str[j]=str[j+1];
                    str[j+1]=temp;
                }
            }
        }

        for(i=N-1; i>=0; i--)
        {
            cout << str[i];
        }

        cout << endl;
    }

    return 0;
}
