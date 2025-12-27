#include<bits/stdc++.h>
using namespace std;
int n;
int a[105],b[105];
int main()
{
    int cnt1=0,cnt2=0;

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]>b[i])
        {
            cnt1++;
        }
        else if(b[i]>a[i])
        {
            cnt2++;
        }
    }

    if(cnt1>cnt2){
        printf("Mishka");
    }
    else if(cnt2>cnt1)
    {
        printf("Chris");
    }
    else{
        printf("Friendship is magic!^^");
    }

    return 0;
}
