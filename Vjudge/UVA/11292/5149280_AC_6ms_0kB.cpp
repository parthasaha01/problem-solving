#include<bits/stdc++.h>
using namespace std;
long int a[20005],b[20005];
int main()
{
    long long int n,m,minn,flag,res;

    while(scanf("%lld %lld",&n,&m)==2)
    {
        if(n==0 && m==0)
            break;

        for(int i=0; i<n; i++){
            scanf("%ld",&a[i]);
        }
        for(int i=0; i<m; i++){
            scanf("%ld",&b[i]);
        }

        if(m<n){
            printf("Loowater is doomed!\n");
        }
        else
        {
            sort(a,a+n);
            sort(b,b+m);
            int i=0;
            int j=0;
            res=0;

            while(i<n && n-i<=m-j)
            {
                if(a[i]<=b[j]){
                    res+=b[j];
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }

            }

            if(i==n){
                printf("%lld\n",res);
            }
            else
            {
                printf("Loowater is doomed!\n");
            }
        }
    }

    return 0;
}
