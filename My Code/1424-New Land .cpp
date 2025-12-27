#include<bits/stdc++.h>
using namespace std;
#define mx 2005
stack<int>st;
char ss[mx][mx];
int aa[mx][mx],LL[mx][mx],RR[mx][mx];
int main()
{
    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int rr,cc;
        scanf("%d%d",&rr,&cc);

        for(int i=1; i<=rr; i++)
            scanf("%s",ss[i]);

        for(int i=1; i<=rr; i++)
        {
            for(int j=1; j<=cc; j++)
            {
                if(ss[i][j-1]=='1')aa[i][j] = 0;
                else aa[i][j] = aa[i-1][j]+1;
            }
        }

        for(int i=1; i<=rr; i++)
        {
            for(int j=1; j<=cc; j++)
            {
                while(!st.empty() && aa[i][st.top()]>aa[i][j])
                {
                    int id = st.top();
                    st.pop();
                    RR[i][id] = j-1;
                }
                st.push(j);
            }
            while(!st.empty())
            {
                int id = st.top();
                st.pop();
                RR[i][id] = cc;
            }

            for(int j=cc; j>=1; j--)
            {
                while(!st.empty() && aa[i][st.top()]>aa[i][j])
                {
                    int id = st.top();
                    st.pop();
                    LL[i][id] = j+1;
                }
                st.push(j);
            }
            while(!st.empty())
            {
                int id = st.top();
                st.pop();
                LL[i][id] = 1;
            }
        }

        int ans=0;
        for(int i=1; i<=rr; i++)
        {
            for(int j=1; j<=cc; j++)
            {
                int area = (RR[i][j]-LL[i][j]+1)*aa[i][j];
                ans = max(ans,area);
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}

/*
10
5 5
10010
10001
00000
10000
11010

*/
