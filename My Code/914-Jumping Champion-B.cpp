#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000005
bool flag[mx+5];
vector<int>pr;
int fr[mx+5];
void sieve()
{
    flag[0]=flag[1]=true;
    for(ll i=2; i<=mx; i++){
        if(!flag[i]){
            pr.push_back(i);
            for(ll j=i*i; j<=mx; j+=i){
                flag[j]=true;
            }
        }
    }
}
int binarySearch(int v)
{
    int id=0;
    int lo=0;
    int hi=pr.size()-1;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        id = md;
        if(pr[md]==v)break;
        else if(pr[md]<v)lo=md+1;
        else hi=md-1;
    }
    return id;
}
int main()
{
    sieve();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int LB,UB; scanf("%d%d",&LB,&UB);
        if(LB>UB)swap(LB,UB);

        int ld = binarySearch(LB);
        if(pr[ld]<LB)ld++;
        int ud = binarySearch(UB);
        if(pr[ud]>UB)ud--;

        memset(fr,0,sizeof(fr));
        bool valid = false;
        int ma,maxx=0;

        for(int i=ld; i<ud; i++){
            int d = pr[i+1]-pr[i];
            fr[d]++;
            if(fr[d]>maxx){
                ma = d;
                maxx = fr[d];
                valid = true;
            }
            else if(fr[d]==maxx)valid = false;
        }

        if(valid)printf("The jumping champion is %d\n",ma);
        else printf("No jumping champion\n");

    }

    return 0;
}
