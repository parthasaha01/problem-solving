#include<bits/stdc++.h>
using namespace std;
int n;
string a,b;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        cin>>a>>b;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]=='.')continue;
            if(a[i]!=b[i])ans++;
        }
        printf("%d\n",ans);
    }
    return 0;

}
