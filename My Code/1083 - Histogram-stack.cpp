#include<bits/stdc++.h>
using namespace std;
#define mx 30005
stack<int>st;
int aa[mx+5],LL[mx+5],RR[mx+5];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++)
            scanf("%d",&aa[i]);

        for(int i=1; i<=n; i++)
        {
            while(!st.empty() && aa[st.top()]>aa[i])
            {
                int id = st.top();
                st.pop();
                RR[id] = i-1;
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int id = st.top();
            st.pop();
            RR[id] = n;
        }

        for(int i=n; i>=1; i--)
        {
            while(!st.empty() && aa[st.top()]>aa[i])
            {
                int id = st.top();
                st.pop();
                LL[id] = i+1;
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int id = st.top();
            st.pop();
            LL[id] = 1;
        }

        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int area = (RR[i]-LL[i]+1)*aa[i];
            ans = max(ans,area);
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}

/*
5
10
3 4 5 2 6 8 3 1 5 10

*/


