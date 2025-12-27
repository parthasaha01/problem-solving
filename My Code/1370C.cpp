#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool vis[100005];
vector<int>primes;
void sieve(){
    for(int i=2; i<=100005; i++){
        if(!vis[i]){
            primes.push_back(i);
            for(int j=i+i; j<=100005; j+=i){
                vis[j] = true;
            }
        }
    }
}
bool solve(int n)
{
    if(n==1){
        return false;
    }else if(n==2 || n%2 == 1){
        return true;
    }else if(n && (!(n&(n-1)))){
        return false;
    }else if(n%4 == 0){
        return true;
    }else{
        int cnt = 0;
        n/=2;
        for(int i=1; i<(int)primes.size() && primes[i]*primes[i]<=n; i++){
            while(n%primes[i]==0){
                cnt++;
                if(cnt>1)return true;
            }
        }
        if(cnt>0 && n>1)return true;
        return false;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();
    int tt; cin>>tt;
    for(int t=1; t<=tt; t ++){
        int n; cin>>n;

        if (solve(n)){
            cout<<"Ashishgup"<<endl;
        }else{
            cout<<"FastestFinger"<<endl;
        }
    }
    return 0;
}

