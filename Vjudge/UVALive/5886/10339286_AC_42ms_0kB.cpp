#include<bits/stdc++.h>
using namespace std;
int n;
char ss[1005][1005],pp[1005][1005],tt[1005][1005];
string ans;
void Rotate()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tt[i][j] = ss[n-j-1][i];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            ss[i][j] = tt[i][j];
        }
    }
}
void calculate()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(ss[i][j]=='O')
            {
                ans+=pp[i][j];
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        ans="";

        for(int i=0; i<n; i++)
        {
            scanf("%s",ss[i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%s",pp[i]);
        }

//        printf("\n");
//        for(int i=0; i<n; i++)
//        {
//            printf("%s\n",ss[i]);
//        }
//        printf("\n");
//        for(int i=0; i<n; i++)
//        {
//            printf("%s\n",pp[i]);
//        }
//        printf("\n");

        calculate();

        Rotate();
        calculate();

        Rotate();
        calculate();

        Rotate();
        calculate();

        cout << ans << endl;
    }

    return 0;
}
