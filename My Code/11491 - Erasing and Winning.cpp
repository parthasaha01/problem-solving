#include<bits/stdc++.h>
using namespace std;
#define maxx 100005
int st[maxx][20];
char s[maxx],s1[maxx];
void create_sptable(int N)
{
    for(int i=0; i<N; i++) st[i][0]=i;

    for(int k=1; (1<<k)<N; k++)
    {
        for(int i=0; i+(1<<k)-1<N; i++)
        {
            int x = st[i][k-1];
            int y = st[i+(1<<(k-1))][k-1];

            if(s[x]>=s[y]) st[i][k]=x;
            else st[i][k]=y;
        }
    }
}
int RMQ(int b,int e)
{
    int x,y,k;

    if(e-b>1){
        k = (int)log2(e-b+1);
        x = st[b][k];
        y = st[e-(1<<k)+1][k];
    }
    else{
        x=b;
        y=e;
    }

    if(s[x]>=s[y]) return x;
    else return y;
}
int main()
{
    int n,d,b,e,p,k;

    while(scanf("%d %d",&n,&d))
    {
        if(n==0 && d==0){
            break;
        }
        getchar();
        gets(s);

        create_sptable(n);

        b=0;e=d;k=0;

        while(e<n)
        {
            p=RMQ(b,e);
            s1[k++]=s[p];
            b=p+1;
            e++;
        }

        s1[k]='\0';
        puts(s1);
    }
    return 0;
}
