#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int f[1005];
int main()
{
    f[0]=1;
    f[1]=1;
    map<int,int>mp;
    mp[1]=1;
    mp[2]=1;

    for(int i=2; i<=100; i++)
    {
        f[i] = f[i-1] + f[i-2];
        if(f[i]>1000)break;
        mp[f[i]] = 1;
       // cout << f[i] << " " << mp[f[i]] << endl;

    }

    int n; scanf("%d",&n);
    string s;
    for(int i=1; i<=n; i++)
    {
        //cout << i << " " <<  mp[i] << endl;
        if(mp[i]==1){
            s += 'O';
        }
        else{
            s += 'o';
        }
    }

    cout << s << endl;
   // main();

    return 0;
}
