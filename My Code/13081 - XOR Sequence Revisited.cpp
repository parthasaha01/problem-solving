#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int T,L,R,diff,res;
    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld %lld",&L,&R);

        if(L>R)
            swap(L,R);

        diff=R-L;

        if(diff>=2){
            res=0;
        }
        else if(diff==1){
            if(L%4==3)
                res=1;
            else
                res=0;
        }
        else{
            if(L%4==0)
                res=L+1;
            else if(L%4==1)
                res=0;
            else if(L%4==2)
                res=L;
            else
                res=1;
        }

        printf("%lld\n",res);
    }

    return 0;
}
