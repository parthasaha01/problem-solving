#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3])
    {
        int sum = arr[0]+arr[1]+arr[2]+arr[3];
        //cout<<sum<<endl;
        long long  mx = 10000000000000;
        for(int i=0; i<4; i++)
        {
            for(int j=i+1; j<4; j++)
            {
                long long res = arr[i]+arr[j];
                long long r = sum - res;
                //cout<<"val "<<res<<endl;
                mx = min(abs(r -res),mx);
            }
        }
        cout<<mx<<endl;
    }
}
