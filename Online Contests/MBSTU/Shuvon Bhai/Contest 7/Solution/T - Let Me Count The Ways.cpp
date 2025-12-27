#include<bits/stdc++.h>
using namespace std;
int arr[5]={1,5,10,25,50};
int ret;
int visited[30000][6];
int store[30000][6];
int f(int taka, int branch)
{
    //cout << taka << " " << branch << " " << ret << endl;

    if(taka<=0)
        return ret;

    //cout << "partha" << endl;

    if(visited[taka][branch]==1)
    {
        return store[taka][branch];
        //cout << "partha" << endl;
    }
    if(arr[branch]>taka)
        f(taka,branch+1);

    for(int note=1; note<=(taka/arr[branch]); note++)
    {
        //cout << "partha" << endl;
        cout << taka << " " << branch << " " << ret << endl;
        ret += f(taka-(note*arr[branch]),branch);
        visited[taka][branch]=1;
        store[taka][branch]=ret;
    }

   // return ret;
}
int main()
{
     int n,m,i,cnt;

     while(cin >> n)
     {
         memset(visited, 0, sizeof(visited));
         memset(store, 0, sizeof(store));

         ret=0;
         cnt = f(n,0);

         cout << cnt << endl;
     }

     return 0;
}
