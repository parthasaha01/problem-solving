#include<bits/stdc++.h>
using namespace std;
string s[1005];
int pp[5][10005],res[10005];
void precalculate()
{
    s[0] = s[1] = "1";
    for(int n=2; n<=1000; n++)
    {
        int m = n;
        int j = 0;
        int ci = 0;
        int sz = s[n-1].size();
        //printf("sz=%d\n",sz);
        //cout << s[n-1] << endl;
        while(m!=0)
        {
            int k = j;
            int d = m%10;

            for(int i=0; i<sz; i++)
            {
                int u = s[n-1][i]-'0';
                int tm = (d*u)+ci;
                int v = tm%10;
                ci = tm/10;
                pp[j][k] = v;
                k++;
            }
            if(ci>0)pp[j][k]=ci;
            j++;
            m /= 10;
        }

        memset(res,0,sizeof(res));

        for(int x=0; x<j; x++)
        {
            for(int y=0; y<=sz+j+1; y++)
            {
                res[y+1] += (res[y]+pp[x][y])/10;
                res[y] = (res[y]+pp[x][y])%10;
            }
        }

        int x = sz+j+3;

        while(res[x]!=0){
            x--;
        }
        s[n]="";
        for(int y=x; y>=0; y--)
        {
            s[n] += res[y]+'0';
        }
    }
}
int main()
{
    precalculate();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d!\n",n);
        cout << s[n] << endl;
    }
    return 0;
}
