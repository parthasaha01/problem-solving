#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        bool flag=true;
        bool cop=false;

        for(int i=0; i<n; i++)
        {
            int p=a[i];

            if(cop==true){
                if(p==0){
                    flag=false;
                    break;
                }
                p=p-1;
                cop=false;
            }

            if(p%2==1){
                cop=true;
            }
        }

        if(flag==false||cop==true){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }

    return 0;
}
