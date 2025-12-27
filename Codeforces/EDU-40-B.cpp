#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int possible(int p)
{
    if((p+p)>n)return 0;

    for(int i=0,j=p; i<p; i++,j++)
    {
        if(s[i]!=s[j])return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    cin>>s;
    int ans = 1000;

    if(n==1){
        cout << "1" << endl;
        return 0;
    }


    for(int i=1; i<n; i++)
    {
        if(possible(i)==1){
            int cnt = i+1;
            cnt += (n-i-i);
            ans = min(ans,cnt);
        }
        else{
            int cnt = n;
            ans = min(ans,cnt);
        }
    }

    cout << ans << endl;

    //main();

    return 0;
}

