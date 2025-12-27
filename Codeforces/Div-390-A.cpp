#include<bits/stdc++.h>
using namespace std;
vector<int>vt;
int a[105];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        vt.clear();

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        if(n==1){
            if(a[1]==0){
                printf("NO\n");
            }
            else{
                printf("YES\n1\n1 1\n");
            }

            continue;
        }

        int st=0;
        for(int i=1; i<=n; i++){
            if(a[i]!=0){
                st=i;
                break;
            }
        }

        if(st==0){
            printf("NO\n");
            continue;
        }

        vt.push_back(1);

        for(int i=st+1; i<=n; i++){
            if(a[i]!=0){
                vt.push_back(i-1);
                vt.push_back(i);
            }
        }
        vt.push_back(n);

        int sz = vt.size();

        printf("YES\n");
        printf("%d\n",sz/2);
        for(int i=0; i<sz; i+=2){
            printf("%d %d\n",vt[i],vt[i+1]);
        }
    }

    return 0;
}
