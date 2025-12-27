#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
int a[mx];
int main()
{
    int n,b,d;

    while(scanf("%d%d%d",&n,&b,&d)==3)
    {
        for(int i=0;i<n; i++)
        {
            scanf("%d",&a[i]);
        }

        int cnt=0;
        int ase=0;

        for(int i=0; i<n; i++)
        {
            if(a[i]>b){
                continue;
            }
            else
            {
                ase+=a[i];

                if(ase>d){
                    cnt++;
                    ase=0;
                }
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}
/*
2 7 10
5 6

1 5 10
7

3 10 10
5 7 7

1 1 1
1
*/
