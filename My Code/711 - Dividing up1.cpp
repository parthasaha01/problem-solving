#include<bits/stdc++.h>
using namespace std;
int a[7];
bool vs[7][60005];
bool ans;
void fun(int p,int v)
{
    if(ans==true)return;
    if(v==0){ ans=true; return; }
    if(p>6)return;

    if(vs[p][v]==true)return;
    vs[p][v]=true;

    for(int m=1; m<=a[p]; m++){
        if(v-(p*m)>=0) fun(p+1,v-(p*m));
    }
    fun(p+1,v);
}
int main()
{
    int ks=0;
    while(1)
    {
        int s=0;
        for(int i=1; i<=6; i++){
            scanf("%d",&a[i]);
            s += (a[i]*i);
        }

        if(s==0)break;

        printf("Collection #%d:\n",++ks);

        if(s&1){
            printf("Can't be divided.\n\n");
            continue;
        }

        int v = s/2;
        ans = false;

        memset(vs,false,sizeof(vs));
        fun(1,v);

        if(ans)printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}

