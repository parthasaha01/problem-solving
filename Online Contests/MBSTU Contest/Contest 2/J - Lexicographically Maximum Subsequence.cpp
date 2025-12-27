#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int main()
{
    char s[mx],ss[mx],rs[mx];
    cin >> s;

    int sz = strlen(s);

    char ch = 'A';
    int k=0;
    for(int i=sz-1; i>=0; i--)
    {
        if(s[i]>=ch)
        {
            ch=s[i];
            rs[k++]=ch;
        }
    }
    rs[k]='\0';
    int p=0;
    for(int i=k-1; i>=0; i--)
    {
        ss[p++]=rs[i];
    }
    ss[p]='\0';
    cout << ss << endl;

    return 0;
}
