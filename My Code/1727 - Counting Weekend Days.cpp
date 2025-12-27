#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,res;
    scanf("%d",&T);
    string m,d;
    while(T--)
    {
        cin >> m >> d;

        if(d=="SUN" || d=="MON" || d=="TUE" || m=="FEB"){
            res=8;
        }
        else if(d=="WED"){
            if(m=="APR" || m=="JUN" || m=="SEP" || m=="NOV"){
                res=8;
            }
            else{
                res=9;
            }
        }
        else if(d=="THU"){
            if(m=="APR" || m=="JUN" || m=="SEP" || m=="NOV"){
                res=9;
            }
            else{
                res=10;
            }
        }
        else if(d=="FRI"){
            res=10;
        }
        else if(d=="SAT"){
            res=9;
        }

        printf("%d\n",res);
    }

    return 0;
}
