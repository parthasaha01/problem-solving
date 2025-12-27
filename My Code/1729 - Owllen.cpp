#include<bits/stdc++.h>
using namespace std;
int a[26];
int main()
{
    int T,v,res;
    string s;

    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        memset(a,0,sizeof(a));

        cin >> s;
        int sz=s.size();

        for(int i=0; i<sz; i++){
            v = s[i]-'a';
            a[v]++;
        }

        sort(a,a+26);

        res=a[0];
        printf("Case %d: %d\n",test,res);
    }

    return 0;
}
