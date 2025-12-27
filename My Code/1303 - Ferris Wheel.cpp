#include<bits/stdc++.h>
using namespace std;
bool vis[25][25];
struct dt
{
    int now;
    bool state;
} fw[25],ew[25];
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n,m;
        scanf("%d%d",&n,&m);

        queue<int>eq;
        queue<int>fq;

        for(int i=1; i<=n; i++)
        {
            eq.push(i);
        }
        for(int i=1; i<=m; i++)
        {
            fq.push(i);
            fw[i].state=false;
        }

        int cnt=n*m;
        memset(vis,false,sizeof(vis));
        int time=0;
        int k=0;
        while(cnt)
        {
            k++;
            int b=fq.front();

            /*int p;
            if(fw[b].state==true){
                p=fw[b].now;
                printf("k=%d b=%d p=%d ",k,b,p);
            }
            else
                printf("k=%d b=%d ",k,b);*/

            time+=5;

            if(!eq.empty())
            {
                int a=eq.front();

                if(fw[b].state==true)   // 1
                {
                    int x=fw[b].now;
                    eq.push(x);
                    fw[b].state=false;
                }

                if(vis[a][b]==false)    //2
                {
                    vis[a][b]=true;
                    fw[b].state=true;
                    fw[b].now=a;
                    //printf("a=%d",a);
                    cnt--;
                    eq.pop();
                }
                else    // 3
                {
                    bool flag=false;
                    queue<int>temp;

                    while(!eq.empty())  //4
                    {
                        int x=eq.front();
                        eq.pop();

                        if(vis[x][b]==false)    //5
                        {
                            flag=true;
                            vis[x][b]=true;
                            fw[b].state=true;
                            fw[b].now=x;
                            //printf("x=%d",x);
                            cnt--;
                            break;
                        }

                        temp.push(x);
                    }

                    while(!eq.empty())  //6
                    {
                        int x=eq.front();
                        eq.pop();
                        temp.push(x);
                    }

                    while(!temp.empty())    //7
                    {
                        int x=temp.front();
                        eq.push(x);
                        temp.pop();
                    }
                }

            }
            else    //8
            {
                if(fw[b].state==true)   //9
                {
                    int a=fw[b].now;
                    eq.push(a);
                    fw[b].state=false;
                }
            }

            fq.pop();
            fq.push(b);
            //printf("\n");
        }
        time+=(5*m);
        printf("Case %d: %d\n",kase,time);
    }

    return 0;
}
