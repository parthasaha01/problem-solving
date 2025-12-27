#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int main()
{
    int maxx = -1000000000;
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=1; i<=n; i++)
    {
        int sum = 0;
        for(int j=1; j<=n; j++){
            sum += a[i][j];
        }

        maxx = max(maxx,sum);
    }

    for(int j=1; j<=n; j++)
    {
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += a[i][j];
        }

        maxx = max(maxx,sum);
    }

    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += a[i][i];
    }
    maxx = max(maxx,sum);

    sum = 0;

    for(int i=1,j=n; i<=n; i++,j--){
        sum += a[i][j];
    }
    maxx = max(maxx,sum);

    printf("%d\n",maxx);

    return 0;

}
