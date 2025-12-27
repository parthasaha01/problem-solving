#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5005];
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    bool flag = false;

    for(int x=1; x<=n; x++)
    {
        int y = a[x];
        int z = a[y];
        if(a[z]==x){
            flag=true;
            break;
        }
    }

    if(flag)printf("YES\n");
    else printf("NO\n");

    //main();

    return 0;
}
