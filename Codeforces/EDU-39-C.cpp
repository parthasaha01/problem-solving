#include<bits/stdc++.h>
using namespace std;
char s[100005],p[100005];
int main()
{
    scanf("%s",s);

    int n = strlen(s);

    char ph='a';
    bool ase=false;
    for(int i=0; i<n; i++)
    {
        if(s[i]==ph)
        {
            ph++;
        }

        if(ph>'z'){
            ase=true;
            break;
        }
    }

    if(ase)
    {
        printf("%s\n",s);
        return 0;
    }

    for(int i=0; i<n; i++){
        p[i] = s[i];
    }
    p[n] = '\0';

    bool flag = false;

    char ch='a';
    for(int i=0; i<n; i++)
    {
        if(s[i]<=ch)
        {
            p[i] = ch;
            ch++;
        }
        if(ch>'z'){
            flag=true;
            break;
        }
    }

    if(flag)
    {
        printf("%s\n",p);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
