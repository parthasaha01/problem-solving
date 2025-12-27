#include<bits/stdc++.h>
using namespace std;
#define mx 2000005
string a,b,s;
int fa[mx],la,ls;
int failure()
{
    fa[0]=0;

    for(int i=1,j=0; i<ls; i++)
    {
        while(s[i]!=s[j]&&j>0)
        {
            j = fa[j-1];
        }

        if(s[i]==s[j])
        {
            fa[i]=j+1;
            j++;
        }
        else
        {
            fa[i]=0; j=0;
        }
    }

    return fa[ls-1];
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        cin>>a;

        b = a; reverse(b.begin(),b.end());
        s = b+"#"+a;
        la = a.size(); ls=s.size();

        int res = failure();
        int ans = (2*la)-res;
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}


