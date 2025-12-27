#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[55];

    while(cin >> s)
    {
        if(s[0]=='#')
            break;

        int flag=0;

        int sz=strlen(s);

        for(int i=sz-1; i>=1; i--){
            if(s[i]>s[i-1]){
                sort(s+i,s+sz);
                for(int j=i; j<sz; j++){
                        //printf("partha\n");
                    if(s[i-1]<s[j]){
                        swap(s[i-1],s[j]);
                        flag=1;
                        goto label;
                    }

                }
            }
        }

        label:

        if(flag)
            cout << s << endl;
        else
            printf("No Successor\n");

    }

    return 0;
}
