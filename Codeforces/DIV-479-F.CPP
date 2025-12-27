#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define inf 1100000000
int L[200005],s[200005];
int n,a[mx];
stack<int>st;
vector<int>vv;
int binarySearch(int v)
{
    int lo=0; int hi=n; int ans=0;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(s[md]==v-1){
            ans=md;
            lo = md+1;
           // break;
        }
        else if(s[md]<v){
           // ans=md;
            lo=md+1;
        }
        else{
            hi = md-1;
        }
    }
    return ans+1;
}
void path(int lis)
{
    for(int i=n; i>=1 && lis>0; i--)
    {
        if(L[i]==lis){
            st.push(i);
            lis--;
        }
    }
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    s[0] = -inf;
    for(int i=1; i<=n; i++)s[i]=inf;

    int lis = 0;

    for(int i=1; i<=n; i++)
    {
        int v = a[i];
        int p = binarySearch(v);
        s[p] = v;
        L[i] = p;
        lis = max(lis,p);
    }

    path(lis);
    printf("%d\n",lis);

    while(!st.empty())
    {
        vv.push_back(st.top());
        st.pop();
    }

    int xx = vv.size();
    for(int i=0; i<xx; i++){
        if(i==xx-1){
            printf("%d\n",vv[i]);
        }
        else{
            printf("%d ",vv[i]);
        }
    }
}
