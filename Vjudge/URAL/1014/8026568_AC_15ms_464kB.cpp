#include<bits/stdc++.h>
using namespace std;
vector<int>pr;
int main()
{
    pr.push_back(2);
    pr.push_back(3);
    pr.push_back(5);
    pr.push_back(7);

    int n;

    while(scanf("%d",&n)==1)
    {
       if(n==0){
            printf("10\n"); continue;
        }
        if(n<10){
            printf("%d\n",n);continue;
        }

        vector<int>factor[10];

        for(int i=0; i<4 && pr[i]<=n; i++)
        {
            while(n%pr[i]==0)
            {
                factor[pr[i]].push_back(pr[i]);
                n/=pr[i];
            }
        }

        if(n>1){
            printf("-1\n"); continue;
        }

        vector<int>ans;

        for(int i=0; i<factor[5].size(); i++) ans.push_back(5);
        for(int i=0; i<factor[7].size(); i++) ans.push_back(7);

        int c2 = factor[2].size()/3;
        int r2 = factor[2].size()%3;
        for(int i=0; i<c2; i++)ans.push_back(8);

        int c3 = factor[3].size()/2;
        int r3 = factor[3].size()%2;
        for(int i=0; i<c3; i++)ans.push_back(9);

        if(r3==1)
        {
            if(r2==0){
                ans.push_back(3);
            }
            else if(r2==1){
                ans.push_back(6);
            }
            else{
                ans.push_back(6);
                ans.push_back(2);
            }
        }
        else
        {
            if(r2==1)
            {
                ans.push_back(2);
            }
            else if(r2==2)
            {
                ans.push_back(4);
            }
        }

        sort(ans.begin(),ans.end());

        for(int i=0; i<ans.size(); i++){
            printf("%d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}
