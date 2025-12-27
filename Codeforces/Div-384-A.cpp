#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int main()
{
    int n,s,d;
    while(scanf("%d%d%d",&n,&s,&d)==3)
    {
        s--;
        d--;
        string a;
        cin >> a;

        if(a[s]==a[d])
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }

        return 0;
    }
}
