#include<bits/stdc++.h>
using namespace std;
int n,a[105],cum[105];
string s;
int fun(int v,int x){
    int sum = 0;
    for(int i=x; i<n; i++){
        sum += a[i];
        if(sum>v)return 0;
        if(sum==v){
            for(int j=i+1; j<n; j++){
                if(a[j]!=0)break;
                i = j;
            }
            sum = 0;
            if(i==n-1)return 1;
        }
    }
    return 0;
}
int main(){
    cin>>n;
    cin>>s;
    //memset(cum,0,sizeof(cum));
    int f = 0;

    for(int i=0; i<n; i++){
        a[i]=s[i]-'0';
        if(i==0)cum[i] = a[i];
        else cum[i] = cum[i-1]+a[i];
    }
    for(int i=0; i<n-1; i++){
        f = fun(cum[i], i+1);
        if(f==1)break;
    }

    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    //main();

    return 0;
}
