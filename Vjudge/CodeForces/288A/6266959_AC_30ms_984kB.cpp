#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main()
{
    int n, k;
    char a[27];
    for(int i=0; i<26; i++){
        a[i]='a'+i;
    }
    while(cin >> n >> k)
    {
        if(n<k || (n>1 && k==1))
        {
            printf("-1\n");
            continue;
        }

        if(n==1){
            printf("a\n");
            continue;
        }
        int p=0;
        for(int i=0; i<n+2-k; i++)
        {
            s[i] = a[p];
            p = 1-p;
        }
        p=2;
        for(int i=n+2-k; i<n; i++)
        {
            s[i]=a[p++];
        }
        s[n]='\0';

        cout << s << endl;
    }

    return 0;
}
