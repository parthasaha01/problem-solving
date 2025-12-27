#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005];

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        sort(a,a+n);
        int cnt=0;
        int x=0;
        for(int i=1; i<n; i++)
        {
            if(a[x]<a[i]){
                cnt++;
                x++;
            }
        }


        printf("%d\n",cnt);
    }

    return 0;
}

/*
16
1 1 1 1 2 2 2 3 3 3 3 4 4 4 5 5

*/
