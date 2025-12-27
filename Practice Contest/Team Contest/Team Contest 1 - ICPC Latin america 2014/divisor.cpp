#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
        ll n;
        while(cin>>n)
        {
            vector<int>vec;
            for(int i=1; i<=n/2; i++)
            {
                if(n%i==0)
                {
                    vec.push_back(i);
                    cout<<i<<endl;
                }
            }
            cout<<vec.size();
        }
}
