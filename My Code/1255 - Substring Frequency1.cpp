#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
string a,b;
int fa[mx],kp[mx],la,lb;
void failure()
{
    fa[0]=0;
    for(int i=1,j=0; i<lb; i++)
    {
        while(b[i]!=b[j]&&j>0)
        {
            j = fa[j-1];
        }

        if(b[i]==b[j])
        {
            fa[i]=j+1;
            j++;
        }
        else
        {
            fa[i]=0; j=0;
        }
    }

}
int KMP()
{
    failure();

    for(int i=0,j=0; i<la; i++)
    {
        while(a[i]!=b[j]&&j>0)
        {
            j = fa[j-1];
        }

        if(a[i]==b[j])
        {
            kp[i]=j+1;
            j++;
            if(j==lb)j=fa[j-1];
        }
        else
        {
            kp[i]=0; j=0;
        }
    }

    int ans=0;
    for(int i=0; i<la; i++)
    {
        if(kp[i]==lb)ans++;
    }
    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        cin>>a>>b;
        la = a.size();
        lb = b.size();

        int ans = KMP();
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
