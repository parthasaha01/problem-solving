#include<bits/stdc++.h>
using namespace std;
char s[105];
int a[105][105],b[105][105];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);

    memset(b,0,sizeof(b));

    for(int i=0; i<n; i++)
    {
        scanf("%s",&s);
        for(int j=0; j<n; j++)
        {
            if(s[j]=='#')
                a[i+1][j+1] = 0;
            else
                a[i+1][j+1] = 1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int cnt = 0;
            //int flag = 0;
            for(int x=0; x<k &&(j+x)<=n; x++)
            {
                int v = j+x;
                if(a[i][v]==0)
                {
                    break;
                }
                else
                {
                    cnt++;
                    if(cnt==k)break;
                }
            }

            if(cnt==k){
                for(int x=0; x<k; x++){
                    int v = j+x;
                    b[i][v]++;
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int cnt = 0;
            //int flag = 0;
            for(int x=0; x<k &&(j+x)<=n; x++)
            {
                int v = j+x;
                if(a[v][i]==0)
                {
                    break;
                }
                else
                {
                    cnt++;
                    if(cnt==k)break;
                }
            }

            if(cnt==k){
                for(int x=0; x<k; x++){
                    int v = j+x;
                    b[v][i]++;
                }
            }
        }
    }

    int row=1,col=1;
    int maxx = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(b[i][j]>maxx){
                maxx = b[i][j];
                row = i;
                col = j;
            }
        }
    }

    cout << row << " " << col << endl;

    return 0;
}
