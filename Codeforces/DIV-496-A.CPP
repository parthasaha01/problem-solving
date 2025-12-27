#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
vector<int>v;
int a[1005];
int main()
{
    int n; cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];

    v.clear();

    a[0]=0;
    int k = 0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]<=a[i-1]){
            v.push_back(k);
            k = 0;
        }

        k++;
    }
    v.push_back(k);

    int p = v.size();
    cout << p << endl;
    for(int i=0; i<p; i++){
        if(i==p-1)cout<<v[i]<<endl;
        else cout<<v[i]<<" ";
    }
    //main();
    return 0;
}
