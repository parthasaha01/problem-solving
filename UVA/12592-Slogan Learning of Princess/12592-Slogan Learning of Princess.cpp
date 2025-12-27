#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int N, Q, i;

    cin >> N;
    getchar();

    string str[N], str1[N], slogan;

    for(i=0; i<N; i++)
    {
        getline(cin, str[i]);
        getline(cin, str1[i]);
    }

    cin >> Q;
    getchar();

    while(Q--)
    {
        getline(cin, slogan);

        for(i=0; i<N; i++)
        {
            if((slogan == str[i]))
            {
                cout << str1[i] << endl;
                break;
            }
        }
    }

    return 0;
}
