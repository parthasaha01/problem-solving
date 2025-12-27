#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>vv;
int n,x,nn;
int main()
{
    int n,x; scanf("%d%d",&n,&x);

    vv.push_back(x);

    if(n==1){
        printf("YES\n");
        printf("%d\n",x);
        return 0;
    }

    nn = n-1;




    printf("YES\n");
    for(int i=0; i<n; i++){
        if(i==n-1)printf("%d\n",vv[i]);
        else printf("%d ",vv[i]);
    }
    return 0;
}
