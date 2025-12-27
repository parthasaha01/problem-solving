#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,s[1005];
vector<int>pr;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&s[i]);
        }

        bool flag = true;
        for(int i=2; i<=n; i++){
            if(s[i]!=s[i-1]){
                flag = false;
                break;
            }
        }

        if(flag==true){
            printf("neutral\n");
            continue;
        }

        flag = true;
        for(int i=2; i<=n; i++){
            if(s[i]<s[i-1]){
                flag = false;
                break;
            }
        }

        if(flag==true){
            printf("allGoodDays\n");
            continue;
        }

        flag = true;
        for(int i=2; i<=n; i++){
            if(s[i]>s[i-1]){
                flag = false;
                break;
            }
        }

        if(flag==true){
            printf("allBadDays\n");
            continue;
        }

        pr.clear();
        for(int i=2; i<=n-1; i++)
        {
            if(s[i]>s[i-1] && s[i]>s[i+1])
            {
                pr.push_back(i);
            }
        }

        int sz = pr.size();

        if(sz<2){
            printf("none\n");
            continue;
        }

        int maxx=0;

        for(int i=1; i<sz; i++)
        {
            int cnt = abs(pr[i]-pr[i-1])-1;
            maxx = max(maxx,cnt);
        }

        printf("%d\n",maxx);
    }
    return 0;
}

