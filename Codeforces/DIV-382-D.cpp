#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x, int y){
    return x>y;
}
int check_prime(int n)
{
    int sq=sqrt(n);
    for(int i=3; i<=sq; i+=2){
        if(n%i==0) return 0;
    }
    return 1;
}
int main()
{
    int n;
    while(cin>>n)
    {
       if(n==2)
       {
            cout << "1" << endl;
       }
       if(n%2==0)
       {
           cout << "2" << endl;
       }
       else
       {
           if(check_prime(n)==1) cout << "1" << endl;
           else{
                if(check_prime(n-2)==1) cout << "2" << endl;
                else cout << "3" << endl;
           }
       }
    }

    return 0;
}


