#include<bits/stdc++.h>
using namespace std;

int d[11],s[11],cd[11];
int main()
{
    int T,res;
    scanf("%d",&T);

    while(T--)
    {
        int n,x,y;
        char z;

        scanf("%d",&n);

        memset(d,0,sizeof(d));
        memset(s,0,sizeof(s));

        for(int i=0; i<n; i++){
            scanf("%d %d %c",&x,&y,&z);
            if(y==1 && z=='c'){
                s[x]++;
            }
            else if(y==0 && z=='i'){
                d[x]++;
            }
        }

        cd[0]=0;
        for(int i=1; i<=10; i++){
            cd[i]=cd[i-1]+d[i];
        }

        int res=0;
        for(int i=1; i<=10; i++){
            res += s[i]*cd[i-1];
        }

        printf("%d\n",res);
    }

    return 0;
}

