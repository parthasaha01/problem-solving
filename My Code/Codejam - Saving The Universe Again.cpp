#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[35];
int a[35];
queue< vector<int> >vv;
vector<int>u;
map< vector<int>, int> mp;
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int d; scanf("%d",&d);
        scanf("%s",&s);
        int n = strlen(s);

        mp.clear();
        u.clear();

        u.push_back(0);
        for(int i=0; i<n; i++){
            if(s[i]=='C')u.push_back(2);
            else u.push_back(1);
        }

        vv.push(u);
        int ans = 10000000;
        int flag = 0;
        while(!vv.empty())
        {
            vector<int>x,y;
            x = vv.front();
            vv.pop();
            for(int i=1; i<=n; i++)y.push_back(x[i]);
            if(mp[y]==1)continue;
            mp[y]=1;
            int cnt = x[0];
            int ret = 0;
            int cur = 1;
            //printf("partha\n");
            //getchar();
            for(int i=1; i<=n; i++){
                if(x[i]==2)cur*=2;
                else{
                    ret += cur;
                }
            }

//            printf("%d: ",x[0]);
//            for(int i=1; i<=n; i++){
//                if(x[i]=='2')printf("C");
//                else printf("S");
//            }
//            printf("  ret=%d\n",ret);

            if(ret<=d){
                flag = 1;

                ans = min(ans,cnt);
                break;
            }
            for(int i=1; i<n; i++)
            {
                swap(x[i],x[i+1]);
                x[0]++;
                vv.push(x);
                x[0]--;
                swap(x[i],x[i+1]);
            }
        }

        if(flag==1)printf("Case #%d: %d\n",ks,ans);
        else printf("Case #%d: IMPOSSIBLE\n",ks,ans);

        while(!vv.empty())vv.pop();

    }

    return 0;
}
