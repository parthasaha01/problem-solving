#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>vv;
int aa[105],bb[105];
int main()
{
    int n, s;
    scanf("%d%d",&n,&s);

    vv.clear();
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&aa[i],&bb[i]);
        int sum = (aa[i]*60)+bb[i];
        vv.push_back(sum);
    }

    if(vv[0]>s){
        printf("0 0\n");
        return 0;
    }

    int cur = 0;
    int ans = 0;
    int need = s+s+2;
    int flag = 0;
    for(int i=1; i<n; i++)
    {
        int d = vv[i]-vv[i-1];
        if(d>=need){
            flag = 1;
            ans = vv[i-1]+s+1;
            break;
        }
    }

    if(flag==1)
    {
        int hh = ans/60;
        int mm = ans%60;
        printf("%d %d\n",hh,mm);
    }
    else if(n>1)
    {
        ans = vv[n-1]+s+1;
        int hh = ans/60;
        int mm = ans%60;
        printf("%d %d\n",hh,mm);
    }
    else
    {
        if(vv[0]>s){
            ans = 0;
        }
        else{
            ans = vv[0]+s+1;

        }

        int hh = ans/60;
        int mm = ans%60;
        printf("%d %d\n",hh,mm);
    }

    main();
    return 0;
}
