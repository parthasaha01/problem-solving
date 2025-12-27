#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d",&n);

    int r = n%10;

    if(r==0){
        printf("%d\n",n);
    }
    else if(r<=5){
        printf("%d\n",n-r);
    }
    else{
        printf("%d\n",n+(10-r));
    }

    return 0;
}
