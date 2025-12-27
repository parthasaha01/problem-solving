#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        int n,m; scanf("%d%d",&n,&m);

        //if(n>m)swap(n,m);
        int nm = n*m;
        int ans;

        if(n==1||m==1)ans = max(n,m);
        else if(n==2||m==2){
            if(n==2&&m==2)ans=nm;
            else if(n==2&&m==3)ans=(nm/2)+1;
            else if(m==2&&n==3)ans=(nm/2)+1;
            else if(n==2){
                if(m%2==1) ans = 2*((m+1)/2);
                else{
                    if(m%4==0) ans = 2*(m/2);
                    else ans = 2*((m/2)+1);
                }
            }
            else if(m==2){
                if(n%2==1) ans = 2*((n+1)/2);
                else{
                    if(n%4==0) ans = 2*(n/2);
                    else ans = 2*((n/2)+1);
                }
            }
        }
        else if(nm%2==0)ans = (nm/2);
        else ans = (nm/2)+1;

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
