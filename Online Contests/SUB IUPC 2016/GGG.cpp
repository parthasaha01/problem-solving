#include<bits/stdc++.h>
using namespace std;
bool flag[10005];
vector<int>pr;
void sieve()
{
    pr.push_back(2);
    for(int i=3; i<=10000; i+=2){
        if(!flag[i]){
            pr.push_back(i);
            for(int j=i*i; j<=10000; j+=i+i){
                flag[j]=true;
            }
        }
    }
}
int binarySearch(int v)
{
    int lo = 0;
    int hi = pr.size()-1;

    int id = -1;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(pr[md]==v){
            id = md;
            break;
        }
        else if(pr[md]<v){
            id = md;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }

    return id;
}
int main()
{
    sieve();

    int qq; scanf("%d",&qq);

    for(int ks=1; ks<=qq; ks++)
    {
        int lf,rg; scanf("%d%d",&lf,&rg);
        if(lf>rg)swap(lf,rg);

        if(rg<2){ printf("-1\n"); continue; }

        int id = binarySearch(rg);

        if(pr[id]<lf)printf("-1\n");
        else printf("%d\n",pr[id]);
    }
    return 0;
}
