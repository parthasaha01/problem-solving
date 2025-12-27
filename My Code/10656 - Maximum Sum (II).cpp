#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,flag;
    int a[1005];
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        flag=0;
        for(int i=0; i<n; i++){
            if(a[i]){
                if(flag)
                printf(" ");
                printf("%d",a[i]);
                flag=1;
            }
        }

        if(flag==0)
            printf("0");
        printf("\n");
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,flag;
    int a[1005];
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        flag=0;
        for(int i=0; i<n; i++){
            if(a[i]){
                if(flag)
                printf(" ");
                printf("%d",a[i]);
                flag=1;
            }
        }

        if(flag==0)
            printf("0");
        printf("\n");
    }

    return 0;
}
