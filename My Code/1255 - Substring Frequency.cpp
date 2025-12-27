#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
string a,b;
int fa[mx],kp[mx],la,lb;
void failure()
{
    fa[0]=0;
    int i=1,j=0;
    while(i<lb)
    {
        if(b[i]==b[j])
        {
            fa[i]=j+1;
            i++; j++;
        }
        else if(j==0)
        {
            fa[i]=0;
            i++;
        }
        else
        {
            j = fa[j-1];
        }
    }
}
int KMP()
{
    failure();
    int i=0,j=0;

    while(i<la)
    {
        if(a[i]==b[j])
        {
            kp[i]=j+1;
            i++; j++;
            if(j==lb)j=fa[j-1];
        }
        else if(j==0)
        {
            kp[i]=0;
            i++;
        }
        else
        {
            j=fa[j-1];
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
