#include<bits/stdc++.h>
using namespace std;
#define mx 2000005
string a,b,s;
int fa[mx];
int failure()
{
    fa[0]=0;
    int ans=0;
    for(int i=1,j=0; i<s.size(); i++)
    {
        while(s[i]!=s[j]&&j>0)
        {
            j = fa[j-1];
        }

        if(s[i]==s[j])
        {
            fa[i]=j+1;
            j++;
            if(fa[i]==b.size())ans++;
        }
        else
        {
            fa[i]=0; j=0;
        }
    }

    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        cin>>a>>b;
        s = b+"#"+a;

        int ans = failure();
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}

