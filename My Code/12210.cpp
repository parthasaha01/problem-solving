#include<bits/stdc++.h>
using namespace std;
int ba[10001],sp[10001];
int main()
{
    int b,s,kase=0;

    while(scanf("%d %d",&b,&s))
    {
        if(b==0 && s==0){
            break;
        }

        for(int i=0; i<b; i++){
            scanf("%d",&ba[i]);
        }
        for(int i=0; i<s; i++){
            scanf("%d",&sp[i]);
        }

        if(b>s)
        {
            int minn=100;
            for(int i=0; i<b; i++){
                if(ba[i]<minn){
                    minn=ba[i];
                }
            }

            printf("Case %d: %d %d\n",++kase,b-s,minn);
        }
        else
        {
            printf("Case %d: 0\n",++kase);
        }
    }

    return 0;
}
