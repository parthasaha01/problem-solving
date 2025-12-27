#include<bits/stdc++.h>
using namespace std;
char s[10][200];
int main()
{
    int n,k;
    cin>>n>>k;

//    if(k%2==1 & k>(n-2))
//    {
//        printf("NO\n");
//        return 0;
//    }

    printf("YES\n");

    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=n; j++)
        {
            s[i][j] = '.';
        }
    }

    if(k%2==1)
    {
        if(k<(n-2))
        {
            int d = n-k;
            int h = d/2;
            int x = h+1;
            for(int i=1; i<=k; i++){
                s[2][x] = '#';
                x++;
            }
        }
        else if(k==(n-2))
        {
            int x = 2;
            for(int i=1; i<=k; i++){
                s[2][x] = '#';
                x++;
            }
        }
        else
        {
            int x = 2;
            for(int i=1; i<=n-2; i++){
                s[2][x] = '#';
                x++;
            }

            k -= n-2;

            x = 2;
            int y = n-1;

            for(int i=1; i<=k; i+=2){
                s[3][x] = '#';
                s[3][y] = '#';
                x++;
                y--;
            }
        }

    }
    else
    {
        int x = 2;
        for(int i=1; i<=k; i++)
        {
            s[2][x] = '#';
            if(i==k) break;
            s[3][x] = '#';
            i++;
            x++;
        }
    }


    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%c",s[i][j]);
        }
        printf("\n");
    }

    return 0;
}
