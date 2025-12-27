#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int ks=0;
    int res=0;

    while(cin>>s)
    {
        if(s=="I")res=1;
        else if(s=="II")res=2;
        else if(s=="III")res=3;
        else if(s=="IV")res=4;
        else if(s=="V")res=5;
        else if(s=="VI")res=6;
        else if(s=="VII")res=7;
        else if(s=="VIII")res=8;
        else if(s=="IX")res=9;
        else if(s=="X")res=10;
        else if(s=="XI")res=11;
        else if(s=="XII")res=12;

        printf("Case %d: %d\n",++ks,res);
    }

    return 0;
}
