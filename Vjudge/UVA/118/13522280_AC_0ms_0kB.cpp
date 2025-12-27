#include<bits/stdc++.h>
using namespace std;
int r,c,sx,sy,dx,dy,flag,chk[51][51];
char ss[105],sd,dd;
int fx[]={+1,-1,+0,-0};
int fy[]={+0,-0,+1,-1};
void BFS(int x,int y,int k)
{
    int n = strlen(ss);
    for(int i=0; i<n; i++)
    {
        if(ss[i]=='L'){
            if(k==0)k=2;
            else if(k==1)k=3;
            else if(k==2)k=1;
            else if(k==3)k=0;
        }
        else if(ss[i]=='R'){
            if(k==0)k=3;
            else if(k==1)k=2;
            else if(k==2)k=0;
            else if(k==3)k=1;
        }
        else{
            int tx = x+fx[k];
            int ty = y+fy[k];

            if(tx>=0&&tx<=r&&ty>=0&&ty<=c){
                x=tx,y=ty,k=k;
            }
            else{
                if(chk[x][y]==0){
                    flag = 0;
                    chk[x][y]=1;
                    break;
                }
            }
        }
    }

    dx=x, dy=y;
    if(k==0)dd='E';
    else if(k==1)dd='W';
    else if(k==2)dd='N';
    else if(k==3)dd='S';
    return;
}
int main()
{
    scanf("%d %d",&r,&c);
    while(scanf("%d %d %c",&sx,&sy,&sd)==3)
    {
        scanf("%s",ss);
        int k;
        if(sd=='E')k=0;
        else if(sd=='W')k=1;
        else if(sd=='N')k=2;
        else if(sd=='S')k=3;
        flag=1;
        BFS(sx,sy,k);
        if(flag){
            printf("%d %d %c\n",dx,dy,dd);
        }
        else{
            printf("%d %d %c LOST\n",dx,dy,dd);
        }
    }
    return 0;
}
