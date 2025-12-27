#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,a[MAXN],L[MAXN],R[MAXN],ans[MAXN];
stack<int>st;
void precalc()
{
    for(int i=n; i>=1; i--){
        while(!st.empty() && a[st.top()]>a[i]){
            L[st.top()] = i+1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        L[st.top()] = 1;
        st.pop();
    }

    for(int i=1; i<=n; i++){
        while(!st.empty() && a[st.top()]>a[i]){
            R[st.top()] = i-1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        R[st.top()] = n;
        st.pop();
    }
}
void solve()
{
    memset(ans,-1,sizeof(ans));
    int minn = 1000000005;
    for(int i=1; i<=n; i++){
        int len = R[i]-L[i]+1;
        ans[len] = max(ans[len],a[i]);
        minn = min(minn,a[i]);
    }
    ans[n]=minn;
    for(int i=n-1; i>=1; i--){
//        if(ans[i]==-1){
//            ans[i] = ans[i+1];
//        }
        ans[i]= max(ans[i],ans[i+1]);
    }

    for(int i=1; i<=n; i++){
        if(i<n)cout<<ans[i]<<" ";
        else cout<<ans[i]<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];

    precalc();
    solve();

    return 0;
}
