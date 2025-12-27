#include <cstdio>
#include <cmath>
#include<iostream>
using namespace std;
#define Max 1000000
#define sqt 1000
long int num[Max];
void sieve()
{
    long int i, j,doubleI;

    num[1]=1;

    for(i=4; i<=Max; i+=2)
        num[i]=1;

    for (i = 3; i <= sqt; i+=2)
   {
      if (!num[i])
     {
        doubleI=i+i;
        for (j = i * i; j <= Max; j += doubleI)
            num[j] = 1;
    }
  }
}
int main()
{
    sieve();

    long long T,N,sq;
    cin >> T;

    while(T--)
    {
        cin >> N;

        sq=sqrt(N);

        if(num[sq]==0 && (sq*sq)==N)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
