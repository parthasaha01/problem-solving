#include<bits/stdc++.h>
using namespace std;
int n;
string a,b;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>a>>b;

    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[i]==b[i])continue;
        if(i==n-1){
            a[i]=b[i];
            ans++;
        }
        else{
            if(a[i]==b[i+1] && a[i+1]==b[i]){
                ans++;
                a[i]=b[i];
                a[i+1]=b[i+1];
            }
            else if(a[i+1]==b[i+1]){
                a[i] = b[i];
                ans++;
            }
            else{
                a[i] = b[i];
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

