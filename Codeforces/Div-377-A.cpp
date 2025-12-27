#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
     ll n,k;

     while(cin>>n>>k)
     {
         ll ans=0;

         ll r=n%10;
         ll r1=r;
         ll p=1;
         bool flag=false;
         while(r1!=0&&r1!=k)
         {
             r1=r*p;
             r1=r1%10;
             flag=true;
             p++;
         }

         if(flag){
            p--;
         }

         cout << p << endl;
     }

     return 0;
}
