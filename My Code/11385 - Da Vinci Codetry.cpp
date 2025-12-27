#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long fib[55],i;
    map<long long,int>mp;
    mp[1]= 1;
    mp[2] = 2;
    fib[1] = 1;
    fib[2] = 2;
    for(i=3; i<=50; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        mp[fib[i]] = i;
    }
    //cout<<fib[49];
    int test,n;
    scanf("%d",&test);
    while(test--)
    {
        string store,output,input;
        long long a[105];
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int mx = 0;
        getchar();
        getline(cin,input);
        int ln = input.size();
        // cout<<"now";
        for(i=0; i<200; i++){
            output+=' ';
        }
        for(i=0; i<ln; i++)
        {
            if(input[i]>='A' && input[i]<='Z')
                store+=input[i];
        }

        for(i=0; i<n; i++)
        {
            int l = mp[a[i]] - 1;
            output[l] = store[i];
            mx = max(mx,l);
        }
        int ck= 0;
        for(i=0; i<=mx; i++)
        {
            cout<<output[i];
        }
        cout<<endl;
    }
    return 0;
}
