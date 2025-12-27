#include<bits/stdc++.h>
using namespace std;
#define maxx 100005
long int st[maxx][25],arr[maxx];
void create_st(long int N)
{
    for(long int i=0;i<N;i++){
        st[i][0]=i;//position of minimum value's from position i to 2^0=1 length
    }

    for(long int j=1; (1<<j)<N; j++)
    {
        for(long int i=0; i+(1<<j)-1<N; i++)
        {
            long int x=st[i][j-1];
            long int y=st[i+(1<<(j-1))][j-1];

            if(arr[x]<=arr[y]) st[i][j]=x;
            else st[i][j]=y;
        }
    }
}
long int RMQ(long int i, long int j)
{
    double d=j-i+1;
    int k=(int)log2(d);
    long int x=st[i][k];
    long int y=st[j-(1<<k)+1][k];
    long int indx;
    if(arr[x]<=arr[y]) indx=x;
    else indx=y;

    return indx;
}
int main()
{
    long int T,N,Q;

    scanf("%ld",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%ld %ld",&N,&Q);

        for(long int i=0; i<N; i++){
            scanf("%ld",&arr[i]);
        }

        create_st(N);

        printf("Case %d:\n",test);
        for(long int k=0; k<Q; k++)
        {
            long int i,j;
            scanf("%ld %ld",&i,&j);
            long int indx=RMQ(i-1,j-1);
            long int res=arr[indx];
            printf("%ld\n",res);
        }
    }

    return 0;
}

