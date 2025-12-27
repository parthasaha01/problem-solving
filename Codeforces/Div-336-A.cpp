#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, s,maxx,res,pos,f,t,sum,tt;

    scanf("%d %d",&n,&s);
    maxx=-1;
    //pos=-1;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&f,&t);
        tt=max(t,s-f);
        sum=f+tt;
        if(sum>maxx){
            maxx=sum;
        }

    }
    printf("%d\n",maxx);

    return 0;
}
