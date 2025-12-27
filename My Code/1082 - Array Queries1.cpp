#include<bits/stdc++.h>
using namespace std;
#define maxx 100005
int st[maxx][25],arr[maxx];
void create_st(int N)
{
    for(int i=1;i<=N;i++){
        st[i][0]=i; //position of minimum value's from position i to 2^0=1 length
    }

    for(int j=1; (1<<j)<=N; j++)
    {
        for(int i=0; i+(1<<j)-1<=N; i++)
        {
            int x=st[i][j-1];
            int y=st[i+(1<<(j-1))][j-1];

            if(arr[x]<=arr[y]) st[i][j]=x;
            else st[i][j]=y;
        }
    }
}
int RMQ(int i,int j)
{
    int k=(int)log2(j-i+1);
    int x=st[i][k];
    int y=st[j-(1<<k)+1][k];
    return min(arr[x],arr[y]);
}
int main()
{
    int T,N,Q;

    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%d %d",&N,&Q);

        for(int i=1; i<=N; i++){
            scanf("%d",&arr[i]);
        }

        create_st(N);

        printf("Case %d:\n",test);

        for(int i=1; i<=Q; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            int res=RMQ(x,y);
            printf("%d\n",res);
        }
    }

    return 0;
}

