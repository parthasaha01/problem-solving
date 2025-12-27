#include<bits/stdc++.h>
using namespace std;
int n,a[25],b[25];
int check(int x){
    int cur = 0;
    for(int i=0; i<n; i++){
        if((x&(1<<i))==0){
            cur += a[i];
            if(cur>=360) cur -= 360;
        }else{
            cur -= a[i];
            if(cur<0) cur += 360;
        }
    }
    if(cur==0 || cur==360)return 1;
    return 0;
}
int fun(){
    for(int i=0; i<(1<<n); i++){
        if(check(i))return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++)cin>>b[i];
    for(int i=0,j=n-1; i<n; i++,j--)a[i]=b[j];

    int ans = fun();
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    //main();
    return 0;
}
