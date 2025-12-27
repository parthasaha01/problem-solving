#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    char s[205];
    char a[]="BG";

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==m)
        {
            k=0;
            for(int i=0; i<n+m; i++){
                s[i]=a[k];
                //printf("%c %c %d\n",s[i],a[k],k);
                k=1-k;
            }
            s[n+m]='\0';
        }
        else if(n>m){
            k=0;
            for(int i=0; i<n+m; i++){
                s[i]=a[k];

                if(i<2*m)
                    k=1-k;
            }
            s[n+m]='\0';
        }
        else{
            k=1;
            for(int i=0; i<n+m; i++){
                s[i]=a[k];

                if(i<2*n)
                    k=1-k;
            }
            s[n+m]='\0';
        }

        puts(s);
    }

    return 0;
}
