#include<bits/stdc++.h>
using namespace std;
int fun(int n)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((i^j)==__gcd(j,i))
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    int t;
   // scanf("%d",&t);
   // while(t--)
    {
      //  for(int i=1;i<100;i++)
        {
            cout<<"  "<<fun(20000000)<<endl;
        }
    }
}
