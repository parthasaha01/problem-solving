#include<bits/stdc++.h>
using namespace std;
int vis[1000005];
string s;
stack<int>st;
int main()
{
    cin>>s;
    int n = s.size();

    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')st.push(i);
        else{
            if(!st.empty()){
                int p = st.top();
                st.pop();
                vis[p] = 1;
                vis[i] = 1;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(vis[i])ans++;
    }

    printf("%d\n",ans);

    return 0;
}
