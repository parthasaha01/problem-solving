#include<bits/stdc++.h>
using namespace std;
#define Mx 1000002
bool isPrime[Mx];
long int phi[Mx];
void seive()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;

    for(int i=1; i<=Mx; i++){
        phi[i]=i;
    }
    /*for(i=1; i<=Mx; i+=2){
        phi[i]=i;
    }*/
    for(int i=4; i<=Mx; i+=2){
        phi[i] = i/2;
        isPrime[i]=false;
    }

    for (int i=3; i<=Mx/2; i+=2)
    {
        if(isPrime[i])
        {
            for (int j=i+i; j<=Mx; j+=i)
            {
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

        if(isPrime[n]==true)
            cout << n-1 << endl;
        else
            cout << phi[n] << endl;
    }

    return 0;
}
