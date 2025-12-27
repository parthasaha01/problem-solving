#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int pi[mx],fa[mx];
string p,t;
int main()
{
    while(cin>>t>>p)
    {
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
                fa[i]=j+1;
                j++;
                if(j==p.size())
                {
                    j=pi[j-1];
                }
            }
            else
            {
                fa[i]=j=0;
            }
        }

        for(int i=0; i<p.size(); i++)
        {
            printf("%d ",pi[i]);
        }
        printf("\n");

        int cnt=0;
        for(int i=0; i<t.size(); i++)
        {
            printf("%d ",fa[i]);
            if(fa[i]==p.size())cnt++;
        }
        printf("\n");
        printf("ans=%d\n",cnt);
    }
    return 0;
}
