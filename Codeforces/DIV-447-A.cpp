#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    int sz = ss.size();

    long long int cnt = 0;

    for(int i=0; i<sz; i++)
    {
        for(int j=i+1; j<sz; j++)
        {
            for(int k=j+1; k<sz; k++)
            {
                if(ss[i]=='Q' && ss[j]=='A' && ss[k]=='Q'){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
