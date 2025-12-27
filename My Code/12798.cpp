#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        int res=0;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<m; j++){
                int goal;
                scanf("%d",&goal);

                if(goal!=0){
                    ++cnt;
                }
            }
            if(cnt==m){
                ++res;
            }
        }

        printf("%d\n",res);
    }

    return 0;
}
