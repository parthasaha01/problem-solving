#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&c);

    if(n==1){
        printf("0\n");
        return 0;
    }

    int pr=1;
    int sum=0;

    for(int i=2; i<=n; i++)
    {
        if(pr==1)
        {
            if(a<=b){
                pr=2;
                sum+=a;
            }
            else{
                pr=3;
                sum+=b;
            }
        }
        else if(pr==2)
        {
            if(a<=c){
                pr=1;
                sum+=a;
            }
            else{
                pr=3;
                sum+=c;
            }
        }
        else
        {
            if(b<=c){
                pr=1;
                sum+=b;
            }
            else{
                pr=2;
                sum+=c;
            }
        }
    }

    printf("%d\n",sum);

    return 0;
}
