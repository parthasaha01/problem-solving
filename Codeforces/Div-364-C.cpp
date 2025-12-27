#include<bits/stdc++.h>
using namespace std;
char s[100005];
int v[135],vis[135],last[135];
vector<char>f;
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        getchar();
        gets(s);

        for(int i=0; i<130; i++)
        {
            v[i]=0;
            vis[i]=0;
            last[i]=-1;
        }

        for(int i=0; i<n; i++)
        {
            if(vis[s[i]]==0)
            {
                f.push_back(s[i]);
                vis[s[i]]=1;
            }
        }

        int sz=f.size();
        int res=9999999;
        int cnt=0,pos;

        for(int i=0; i<n; i++)
        {
            char ch=s[i];
            last[ch]=i;

            if(v[ch]==0)
            {
                v[ch]=1;
                cnt++;

                if(cnt==sz)
                {
                    int maxx=0, minn=9999999;

                    for(int k=0; k<sz; k++)
                    {
                        char c=f[k];

                        minn = min(minn,last[c]);
                        maxx = max(maxx,last[c]);
                    }

                    res = min(res,maxx-minn+1);
                    pos=i;
                    break;
                }
            }
        }

        for(int i=pos+1; i<n; i++)
        {
            char ch=s[i];
            last[ch]=i;

            int maxx=0, minn=9999999;

            for(int k=0; k<sz; k++)
            {
                char c=f[k];

                minn = min(minn,last[c]);
                maxx = max(maxx,last[c]);
            }

            res = min(res,maxx-minn+1);
        }

        printf("%d\n",res);
        f.clear();
    }

    return 0;
}
/*
20
OCOCOCCCOOiCOCCOOiOi
*/

