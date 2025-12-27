#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,a,b;

    while(cin>>k>>a>>b)
    {
        if(a<b)swap(a,b);

        if(a<k && b<k){
            printf("-1\n");
            continue;
        }

        if(a<k){
            if(b%k!=0){
                printf("-1\n");
                continue;
            }
        }

        if(b<k){
            if(a%k!=0){
                printf("-1\n");
                continue;
            }
        }

//        int d = abs(a-b);
//        int r = d/k;
//        a-=(r*k);

        int ans=0;

        ans = (a/k) + (b/k);

        printf("%d\n",ans);

    }

    return 0;

}
