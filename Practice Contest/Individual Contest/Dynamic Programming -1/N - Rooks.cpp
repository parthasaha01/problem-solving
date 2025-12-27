#include<bits/stdc++.h>
using namespace std;
#define LL long long int
LL nCr[31][31];
void combination()
{
    int i,j;
    nCr[1][0]=nCr[1][1]=1;
    for(i=2; i<=30; i++){
        nCr[i][0]=1;
        for(j=1;j<i;j++){
            nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
        }
        nCr[i][j]=1;
    }
}
int main()
{
    combination();
    int T,N,R;
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%d %d",&N,&R);
        LL fact=1;
        for(int i=1,k=N; i<=R; i++,k--){
            fact*=k;
        }
        printf("Case %d: %lld\n",test,fact*nCr[N][R]);
    }

    return 0;
}
