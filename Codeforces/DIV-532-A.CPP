#include<bits/stdc++.h>
using namespace std;
int n,k,a[105],x[105];
int fun(int b){
    for(int i=1; i<=n; i++)x[i]=a[i];
    for(int i=-505; i<=505; i++){
        int c = b + (i*k);
        if(c>=1 && c<=n){
            x[c] = 0;
        }
    }
    int p=0, q=0;
    for(int i=1; i<=n; i++){
        if(x[i]==1)p++;
        else if(x[i]==-1)q++;
    }

    int temp = abs(p-q);
    return temp;
}
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        int temp = fun(i);
        ans = max(ans,temp);
    }

    cout << ans << endl;

    //main();

    return 0;
}
