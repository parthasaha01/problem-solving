#include<bits/stdc++.h>
using namespace std;
int n,height,a[200005];
bool possible(){
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(a[i]==height)cnt++;
    }
    if(cnt==n)return true;


}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    height = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        height = max(height, a[i]);
    }


    if(possible()==true){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    //main();
    return 0;
}

