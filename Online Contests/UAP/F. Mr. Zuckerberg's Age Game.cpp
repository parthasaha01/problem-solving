#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        bool f = false;

        for(int i=2; i<n; i++){
            if(n%i==0){
                f = true;
                break;
            }
        }

        if(f)cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}
