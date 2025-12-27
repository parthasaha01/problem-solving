#include<bits/stdc++.h>
using namespace std;
const int MAXN = 30000000;
int cnt[MAXN+5],sum[MAXN+5];
void fun()
{
    for(int G=1; G<=MAXN; G++){
        for(int A=G+G; A<=MAXN; A+=G){
            int B = A-G;
            //if((A^B)==__gcd(A,B))cnt[A]++;
            if((A^B)==(A-B))cnt[A]++; // here GCD(A,B)=(A-B)
        }
    }

    for(int i=1; i<=MAXN; i++){
        sum[i] = sum[i-1]+cnt[i];
    }
}
int main()
{
    fun();

    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        printf("Case %d: %d\n",ks,sum[n]);
    }
    return 0;
}
