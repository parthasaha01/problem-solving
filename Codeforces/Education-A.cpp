#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ss,tt;
    cin>>ss;

    for(int i=1; i<=12; i++)
    {
        tt = ss;
        reverse(tt.begin(),tt.end());

        if(ss==tt){
            printf("YES\n");
            return 0;
        }
        ss = "0"+ss;
    }

    printf("NO\n");

    return 0;
}
