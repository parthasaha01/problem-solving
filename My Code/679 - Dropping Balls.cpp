#include<bits/stdc++.h>
using namespace std;
int power[25];
int fun(int d,int k)
{
    int node = 1;
    for(int depth=1; depth<d; depth++)
    {
        int r = k%power[depth];
        int h = power[depth]/2;

        if((r==0) || (r>h)){
            node = node*2+1;
        }
        else{
            node = node*2;
        }
    }
    return node;
}
int main()
{
    power[0] = 1;
    for(int i=1; i<=21; i++){
        power[i] = power[i-1]*2;
    }

    int n;
    while(scanf("%d",&n))
    {
        if(n==-1)break;

        for(int q=1; q<=n; q++)
        {
            int d,k; scanf("%d%d",&d,&k);
            int ans = fun(d,k);
            printf("%d\n",ans);
        }

    }
    return 0;
}
