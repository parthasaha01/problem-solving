#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    long int mw,cnt,n,weight;
    long int m[100005];
    while(T--)
    {
        scanf("%ld%ld",&n,&mw);

        for(int i=0; i<n; i++){
            scanf("%ld",&m[i]);
        }

        sort(m,m+n);

        cnt=0;
        weight=0;
        for(int i=0; i<n; i++){
            weight+=m[i];

            if(weight>mw){
                break;
            }
            ++cnt;
        }
        printf("%ld\n",cnt);
    }

    return 0;
}
