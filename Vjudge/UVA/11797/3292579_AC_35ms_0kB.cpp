#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
string str[5] = {"Ja","Sam","Sha","Sid","Tan"};
int GetPosition(string name)
{
    int i, position;

    for(i=0; i<5; i++)
    {
        if(str[i]==name)
        {
            position=i;
            break;
        }
    }

    return position;
}
int main()
{
    string name,List;
    int T,M,N,test,i,j;
    int k[5],position;

    scanf("%d",&T);

    for(test=1; test<=T; test++)
    {
        queue< string > q[5];
        int time[5]={0};

        cin >> M >> N >> name;

        for(i=0;i<5;i++)
        {
            cin >> k[i];

            for(j=0;j<k[i];j++)
            {
                cin >> List;

                q[i].push(List);
            }
        }

        position = GetPosition(name);


        while(N>0)
        {
            if(N>=M)
                time[position]+=M;
            else
                time[position]+=N;

            N -= (M+2);

            name = q[position].front();
            q[position].pop();
            q[position].push(name);

            position = GetPosition(name);


        }

        cout << "Case " << test << ":" << endl;

        for(i=0;i<5;i++)
        {
            cout << str[i] << " " << time[i] << endl;
        }

    }
}
