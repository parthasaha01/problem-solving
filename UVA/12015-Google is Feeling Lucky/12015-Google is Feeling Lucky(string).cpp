#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int Max, i, j, T, test = 1;
    int ara[10];
    string str[100];

    cin >> T;
    getchar();

    while(T--)
    {
        Max=0;

        for(i=0; i<10; i++)
        {
            cin >> str[i] >> ara[i];

            if(ara[i] > Max)
                Max = ara[i];
        }

        printf("Case #%d:\n", test++);

        for(i=0; i<10; i++)
        {
            if(Max == ara[i])
                cout << str[i] << endl;
        }
    }

    return 0;
}
