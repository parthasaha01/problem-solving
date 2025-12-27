#include<bits/stdc++.h>
using namespace std;
#define Mx 1000002
#define Hmx 500001
bool isPrime[Mx];
long int phi[Mx];
void seive()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;
    phi[1]=1;
    phi[2]=1;

    for(int i=3; i<=Mx; i++){
        phi[i]=i;
    }
    for(int i=4; i<=Mx; i+=2){
        phi[i] = i/2;
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
    seive();

    long int n,T;

    cin >> T;
    while(T--)
    {
        cin >> n;

        cout << phi[n] << endl;

        /*if(isPrime[n]==true)
            cout << n-1 << endl;
        else
            cout << phi[n] << endl;*/
    }

    return 0;
}
