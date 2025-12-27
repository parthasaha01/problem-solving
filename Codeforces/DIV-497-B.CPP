#include<bits/stdc++.h>
using namespace std;
#define lll long long
#define mx 100005
int n,w[mx],h[mx];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>w[i]>>h[i];
        if(w[i]>h[i])swap(w[i],h[i]);
    }

    //if(w[1]>h[1])swap(w[1],h[1]);
    int f = 1;
    for(int i=2; i<=n; i++){
        if(w[i]>h[i-1]&&h[i]>h[i-1]){
            f = 0;
            break;
        }
        if(h[i]>h[i-1]){
            swap(w[i],h[i]);
        }
    }

    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    //main();

    return 0;
}

