#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,a[MAXN],lft[MAXN],rgt[MAXN];
void preprocess()
{
    lft[1]=0;
    for(int i=2; i<=n; i++){
        if(a[i]>a[i-1])lft[i]=lft[i-1]+1;
        else lft[i] = 0;
    }

    rgt[n]=0;
    for(int i=n-1; i>=0; i--){
        if(a[i]<a[i+1])rgt[i]=rgt[i+1]+1;
        else rgt[i] = 0;
    }
}
int solve()
{
    preprocess();

    int ans = 1;
    for(int i=1; i<=n; i++){
        ans = max(ans,lft[i]+rgt[i]+1);
        if(a[i]<=a[i-1]&&i>1){
            int v = a[i-1]+1;
            int cnt = lft[i-1]+1;
            cnt++;
            if(i<n && v<a[i+1]){
                cnt += rgt[i+1]+1;
            }
            ans = max(ans,cnt);
        }
        if(a[i]>=a[i+1]&&i<n){
            int v = a[i+1]-1;
            int cnt = rgt[i+1]+1;
            cnt++;
            if(i>1 && v>a[i-1]){
                cnt += lft[i-1]+1;
            }
            ans = max(ans,cnt);
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];

    cout << solve() << endl;

    return 0;
}
