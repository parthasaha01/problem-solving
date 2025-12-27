#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
int a[1000005];
void fun()
{
    a[1]=4;
    a[2]=6;

    int v=3;
    int p=8;
    int x=2;
    while(v<=mx)
    {
        for(int i=1; i<=x; i++){
            a[v]=p;
            v++;
            if(v>mx)return;
        }
        p+=2;
        for(int i=1; i<=x; i++){
            a[v]=p;
            v++;
            if(v>mx)return;
        }
        x++;
        p+=2;
    }
}
int main()
{
    fun();

    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",a[n]);
    }

    return 0;
}
