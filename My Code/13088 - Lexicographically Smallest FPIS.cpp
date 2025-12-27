#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    char s[1005];

    while(T--)
    {
        cin >> s;
        int sz=strlen(s);

        sort(s,s+sz);
        char ch=s[0];
        for(int i=1; i<sz; i++)
        {
            if(s[i]==s[i-1]){
                s[i-1]=ch;
            }
        }

        sort(s,s+sz);

        cout << s << endl;
    }

    return 0;
}
