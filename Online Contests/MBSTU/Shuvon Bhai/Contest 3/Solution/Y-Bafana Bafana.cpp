#include<cstdio>
using namespace std;
int main()
{
    int T,N,K,P,i,j;

    scanf("%d",&T);

    for(i=1; i<=T; i++)
    {
        scanf("%d %d %d", &N, &K, &P);

        for(j=1; j<=P; j++)
        {
            ++K;
            if(K>N)
            {
                K=1;
            }
        }
        printf("Case %d: %d\n",i,K);
    }

    return 0;
}
