#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
int n,pi[mx],fa[mx];
string p,t;
int main()
{
    int ks=0;
    while(cin>>n)
    {
        if(ks>0)printf("\n");ks++;

        cin>>p; cin>>t;

        pi[0]=0;
        for(int i=1,j=0; i<p.size(); i++)
        {
            while(p[i]!=p[j] && j>0)
            {
                j=pi[j-1];
            }

            if(p[i]==p[j])
            {
                pi[i]=j+1;
                j++;
            }
            else
            {
                pi[i]=j=0;
            }
        }

        for(int i=0,j=0; i<t.size(); i++)
        {
            while(t[i]!=p[j] && j>0)
            {
                j=pi[j-1];
            }

            if(t[i]==p[j])
            {
                //printf("t[%d]=%c p[%d]=%c\n",i,t[i],j,p[j]);
                fa[i]=j+1;
                j++;
                if(j==p.size())
                {
                    printf("%d\n",i-n+1);
                    j=pi[j-1];
                }
            }
            else
            {
                fa[i]=j=0;
            }
        }
    }
    return 0;
}

