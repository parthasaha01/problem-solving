#include<bits/stdc++.h>
using namespace std;
//ios_base::sync_with_stdio(0); cin,tie(0);
char s[100005];
int main()
{
    while(cin >> s)
    {
        int sz = strlen(s);
        int pos=0;
        bool flag=false;

        for(int i=0; i<sz; i++){
            if(s[i]=='0'){
                pos=i;
                flag=true;
                break;
            }
        }

        if(flag)
        {
            for(int i=pos; i<sz; i++){
                s[i] = s[i+1];
            }
        }
        else{
            s[sz-1]='\0';
        }

        puts(s);
    }

    return 0;
}
