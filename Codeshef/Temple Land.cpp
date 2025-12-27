#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int s; scanf("%d",&s);

    for(int ks=1; ks<=s; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++) scanf("%d",&a[i]);

        if(n%2==0)printf("no\n");
        else{
            int hh = (n/2)+1;
            bool flag=true;
            for(int i=1; i<=hh; i++){
                if(a[i]!=i){
                    flag=false;
                    break;
                }
            }

            if(flag){
                for(int i=n,j=1; i>hh; i--,j++){
                    if(a[i]!=j){
                        flag=false;
                        break;
                    }
                }
            }

            if(flag)printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
