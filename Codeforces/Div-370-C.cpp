#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll s[4];
int main()
{
    ll x,y;

    while(scanf("%I64d%I64d",&x,&y)==2)
    {
        s[0]=y;
        s[1]=y;
        s[2]=y;
        sort(s,s+3);
        ll cnt=0;


        while(1)
        {
            //printf("%I64d %I64d %I64d\n",s[0],s[1],s[2]);
            if(s[0]==x&&s[1]==x&&s[2]==x){
                break;
            }

            if(s[1]+s[2]-1>x){
                s[0]=x;
            }
            else{
                s[0]=s[1]+s[2]-1;
            }

            cnt++;
            sort(s,s+3);
        }

        printf("%I64d\n",cnt);

    }

    return 0;
}
