#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 2000005
int a[MAXN],cnt[MAXN],b[MAXN];
int main()
{
    int n;

    while(scanf("%d", &n) && n != 0)
    {
        int maxx = 0;
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
            maxx = max(maxx,a[i]);
        }

        //sort(ara, ara+n);

        int k = 0;
        for(int i=0; i<=maxx; i++){
            while(cnt[i]){
                b[k++] = i;
                cnt[i]--;
            }
        }

        for(int i=0; i<n; i++)
        {
            printf("%d", b[i]);

            if(i < n-1) printf(" ");
        }

        printf("\n");
    }

    return 0;
}

