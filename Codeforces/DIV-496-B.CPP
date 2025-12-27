#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
string s,t;
int main()
{
    cin>>s;
    cin>>t;

    int n = s.size();
    int m = t.size();

    int ans = n+m;

    for(int i=n-1,j=m-1; i>=0&&j>=0; i--,j--){
        if(s[i]==t[j])ans-=2;
        else break;
    }

    cout << ans << endl;

    //main();
    return 0;
}
