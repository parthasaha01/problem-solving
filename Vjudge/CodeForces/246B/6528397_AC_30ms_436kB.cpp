#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[10005];
int main()
{
    int n,res;

    while(scanf("%d",&n)==1)
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }

        if(sum%n==0){
            res=n;
        }
        else{
            res=n-1;
        }


        printf("%d\n",res);

    }

    return 0;
}

/*
2
2 1
3
1 4 1
9
1 2 2 2 4 5 7 10 11
9
2 2 2 2 4 5 7 10 11
9
7 10 14 1 2 2 2 3 5
9
1 2 2 2 3 5 7 10 14
9
7 10 11 1 2 2 2 3 5
*/
