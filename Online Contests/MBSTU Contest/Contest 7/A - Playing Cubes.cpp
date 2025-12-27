#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        if(n<m){
            swap(n,m);
        }
        printf("%d %d\n",n-1,m);
    }

    return 0;
}
