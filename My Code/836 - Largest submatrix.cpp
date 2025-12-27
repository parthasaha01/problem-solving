#include<bits/stdc++.h>
using namespace std;
string s[30];
int a[30][30],c[30][30],v[30],kd[30];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        cin>>s[1];
        int n = s[1].size();
        for(int i=2; i<=n; i++)cin>>s[i];

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                a[i][j] = s[i][j-1]-'0';
                if(a[i][j]==0)a[i][j]=-1000000;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                c[i][j]=c[i][j-1]+a[i][j];
            }
        }

        int ans=-100000000;

        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                for(int k=1; k<=n; k++){
                    v[k] = c[k][j]-c[k][i-1];
                }
                for(int x=1; x<=n; x++){
                    kd[x]=kd[x-1]+v[x];
                    if(kd[x]<0)kd[x]=0;
                    ans = max(ans,kd[x]);
                }
            }
        }
        printf("%d\n",ans);
        if(ks<tt)printf("\n");
    }
    return 0;
}

/*

20

10111000
00010100
00111000
00111010
00111111
01011110
01011110
00011110


0


1


00
11


01
10


01
11


11
11


01
01


1001
1011
1011
1101
*/

