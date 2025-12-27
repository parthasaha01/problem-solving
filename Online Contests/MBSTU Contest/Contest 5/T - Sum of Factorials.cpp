#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[20];
void factorial()
{
    a[0]=1;
    for(int i=1; i<20; i++)
    {
        a[i] = a[i-1]*i;
    }

    return;
}
bool recursion(int pos, ll n)
{
    if(n==0 || n==a[pos]){
        return true;
    }

    if(n>=a[pos]){
        recursion(pos+1,n-a[pos]);
    }

}
int main()
{
    factorial();

}
