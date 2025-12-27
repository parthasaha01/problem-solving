#include<bits/stdc++.h>
using namespace std;
int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--){
        //int n,p; cin>>n>>p;
        for(int n=3; n<=3; n++){
            for(int p=n; p<=25; p++){
                int ans = 0, cnt = 0, res=(n-1)/2;
                int _i=0, _j=0, _k=0;
                for(int i=1; i<=p; i++){
                    for(int j=1; j<=p; j++){
                        for(int k=1; k<=p; k++){
                            int temp = (((n%i)%j)%k)%n;
                            if(temp>ans){
                                _i = i, _j = j, _k = k;
                                ans = temp;
                            }
                            if(temp==res){
                                cout<<i<<" "<<j<<" "<<k<<endl;
                                cnt++;
                            }
                        }
                    }
                }
                printf("n=%d p=%d ans=%d cnt=%d\n",n,p,ans,cnt);
                getchar();
            }
        }
    }
}
