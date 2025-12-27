#include<bits/stdc++.h>
using namespace std;
#define Mx 1000002
bool isPrime[Mx];
int phi[Mx];
void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;
    phi[1]=1;

    for(int i=2; i<=Mx; i++){
        phi[i]=i;
    }
    for(int i=2; i<=Mx; i+=2){
        phi[i] = phi[i]/2;
        isPrime[i]=false;
    }

    for (int i=3; i<=Mx; i+=2){
        if(isPrime[i]){
                phi[i]=i-1;
            for (int j=i+i; j<=Mx; j+=i){
                phi[j] -= (phi[j]/i);
                isPrime[j]=false;
            }
        }
    }
}
int main()
{
    sieve();

    int n,T;

    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << phi[n] << endl;
    }

    return 0;
}
