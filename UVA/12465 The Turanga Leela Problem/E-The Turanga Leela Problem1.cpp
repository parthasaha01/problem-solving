#include<bits/stdc++.h>
using namespace std;
#define sq 316
#define inf 100005
vector<long>p;
bool chk[inf+2];
void prime()
{
    p.push_back(2);
    for(int i=3; i<sq; i+=2){
        if(!chk[i]){
            p.push_back(i);
            for(int j=i*i; j<=inf; j+=(i<<1)){
                chk[j]=true;
            }
        }
    }
    for(int i=sq+1; i<=inf; i+=2){
        if(!chk[i])
            p.push_back(i);
    }
}
long Divisors(long n)
{
    long res=1,cnt;

    for(int i=0; p[i]*p[i]<=n; i++){
        cnt=0;
        while(n%p[i]==0){
            cnt++;
            n=n/p[i];
        }
        res=res*(cnt+1);
    }

    if(n>1)
        res=(res<<1);

    return res;
}
int main()
{
    prime();
    long a,b,n;

    while(scanf("%ld %ld",&a,&b))
    {
        if(!a && !b)
            break;
        n=abs(a-b);
        printf("%ld\n",Divisors(n));
    }

    return 0;
}


