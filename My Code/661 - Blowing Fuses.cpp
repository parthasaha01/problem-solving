#include<bits/stdc++.h>
using namespace std;
long int need[25],seq[100000],sit[25];
int main()
{
    long int n,m,c,maxx,test=0,cur,flag;

    while(scanf("%ld%ld%ld",&n,&m,&c))
    {
        if(n==0 && m==0 && c==0){
            break;
        }

        memset(sit,0,sizeof(sit));

        for(int i=0; i<n; i++){
            scanf("%ld",&need[i]);
        }
        for(int i=0; i<m; i++){
            scanf("%ld",&seq[i]);
        }

        maxx=0;
        cur=0;
        flag=1;

        for(int i=0; i<m; i++){
            if(sit[seq[i]-1]==0){
                cur += need[seq[i]-1];
                sit[seq[i]-1]=1;

                if(cur>maxx){
                    maxx=cur;
                }
                if(cur>c){
                    flag=0;
                    break;
                }
            }
            else
            {
                sit[seq[i]-1]=0;
                cur = cur-need[seq[i]-1];
            }
        }

        printf("Sequence %ld\n",++test);

        if(flag){
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %ld amperes.\n\n",maxx);
        }
        else
        {
            printf("Fuse was blown.\n\n");
        }
    }

    return 0;
}
