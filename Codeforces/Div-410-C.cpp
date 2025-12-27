#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<deque>
#include<algorithm>
#define si(n) scanf("%d",&n)
#define ss(s) scanf("%s",s)
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    char a[20];
    ss(a);
    int i,j,z=strlen(a),t=0;
    if(z==1)
        return cout<<"YES"<<endl,0;
    for(i=0;i<z/2;i++)
    {
        if(a[i]!=a[z-i-1])
            t++;
        //cout<<t<<endl;
    }
    if(t==0)
    {
        if(z%2)
            t=1;
        else
            t=2;
    }
    if(t!=1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}
