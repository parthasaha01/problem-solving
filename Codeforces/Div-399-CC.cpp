#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int a[MAX+5],b[MAX+5];
struct dt
{
    int mx,mn;
}vv[MAX+5];
int main()
{
    int n,k,x;
    while(scanf("%d%d%d",&n,&k,&x)==3)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        sort(a+1,a+n+1);
        vv[0].mx = a[n];
        vv[0].mn = a[1];

        if(k==0){
            printf("%d %d\n",a[n],a[1]);
            continue;
        }


        for(int i=1; i<=n; i++)b[i]=a[i];
        int cn=0;
        int kn=k;
        while(kn--)
        {
            for(int i=1; i<=n; i+=2){
                b[i] = b[i]^x;
            }

            sort(b+1,b+n+1);
            cn++;
            vv[cn].mx = b[n];
            vv[cn].mn = b[1];
            bool flag = true;
            for(int i=1; i<=n; i++){
                if(a[i]!=b[i]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                break;
            }
        }

        if(cn==k){
            printf("%d %d\n",vv[cn].mx,vv[cn].mn);
        }
        else{
            int r = k%cn;
            printf("%d %d\n",vv[cn].mx,vv[cn].mn);
        }
    }
    return 0;
}
