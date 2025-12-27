#include<bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define ll long long
string s;
int n,fr[10];

int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    n = s.size();
    int ans = 9;
    int minn = 9;
    for(int i=n-1; i>=0; i--)
    {
       int d = s[i]-'0';
       if(d==0){
           fr[d]++;
           continue;
       }
       if(d<minn){
            ans = d;
            minn = d;
            for(int k=0; k<=8; k++){
                if(fr[k]>0){
                    ans--;
                    break;
                }
            }
            if(ans==0)ans++;
       }

       fr[d]++;
    }

    cout << ans << endl;

   // main();
    return 0;
}

