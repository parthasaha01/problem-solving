#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int n;
string a,b;
int solve()
{
    int ans = 0;
    for(int i=0,j=n-1; i<=j; i++,j--)
    {
        if(i==j)
        {
            if(a[i]!=b[i])ans++;
        }
        else
        {
            char a0,a1;
            char b0,b1;
            a0=a[i]; a1=a[j];
            b0=b[i]; b1=b[j];

            set<char>ss;
            ss.insert(a0);
            ss.insert(a1);
            ss.insert(b0);
            ss.insert(b1);

            int sz = ss.size();
            if(sz==1)continue;
            else if(sz==2){
                if(a0==a1){
                    if(a0==b0 || a0==b1){
                        ans+=1;
                    }
                }
                else if(b0==b1)
                {
                    if(b0==a0 || b0==a1){
                        ans+=1;
                    }
                }

            }
            else if(sz==3){
                if(a0==a1)ans+=2;
                else ans += 1;
            }
            else{
                ans+=2;
            }
        }
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    cin>>a;
    cin>>b;

    int ans = solve();
    cout<<ans<<endl;

   // main();

    return 0;
}

