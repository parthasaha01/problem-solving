#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,x,y; cin>>n>>x>>y;
    for(int i=1; i<=n; i++)cin>>a[i];

    sort(a+1,a+n+1);

    int choto=0, soman=0, boro=0;
    for(int i=1; i<=n; i++){
        if(a[i]<x)choto++;
        else if(a[i]==x)soman++;
        else boro++;
    }

    if(x>y){
        cout<<n<<endl;
    }else if(x==y){
        if(choto==0 && soman==0){
            cout<<"0"<<endl;
        }else{
            int sum = choto+soman;
            int ans = sum/2;
            if(sum%2==1)ans++;
            cout<<ans<<endl;
        }
    }else{
        if(choto==0 && soman==0){
            cout<<"0"<<endl;
        }else{
            int sum = choto+soman;
            int ans = sum/2;
            if(sum%2==1)ans++;
            cout<<ans<<endl;
        }
    }

    //main();

    return 0;
}
