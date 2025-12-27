#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int r = sqrt(n);

        for(int i=r; i>=1; i--){
            if(n%i==0){
                printf("%d %d\n",i,n/i); break;
            }
        }
    }

    return 0;
}
