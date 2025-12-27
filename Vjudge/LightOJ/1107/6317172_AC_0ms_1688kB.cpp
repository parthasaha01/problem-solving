#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x1,x2,y1,y2,x,y,m;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);

        printf("Case %d:\n",kase);

        if(x1<x2){
            swap(x1,x2);
        }

        if(y1<y2){
            swap(y1,y2);
        }

        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);

            if((x<=x1&&x>=x2)&&(y<=y1&&y>=y2)){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }

    return 0;
}
