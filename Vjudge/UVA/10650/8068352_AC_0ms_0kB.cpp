#include<bits/stdc++.h>
using namespace std;
#define mx 32050
bool start[mx+5],stop[mx+5],flag[mx+5];
vector<int>pr;
void sieve()
{
    pr.push_back(2);
    for(int i=3; i<=mx; i+=2){
        if(!flag[i]){
            pr.push_back(i);
            for(int j=i*i; j<=mx; j+=2*i) flag[j]=true;
        }
    }
}
void precalculation()
{
    int sz = pr.size();
    for(int i=1; i<sz-2; i++){
        if(pr[i+1]-pr[i] == pr[i+2]-pr[i+1]){
            start[pr[i]]=true;
            int d = pr[i+1]-pr[i];
            int j=i+2;
            while(j<sz-1 && pr[j+1]-pr[j]==d)j++;
            stop[pr[j]]=true;
            i=j-1;
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
    precalculation();

    int LB,UB;
    while(scanf("%d%d",&LB,&UB))
    {
        if(!LB&&!UB)break;
        if(LB>UB)swap(LB,UB);

        int ld = binarySearch(LB);
        if(pr[ld]<LB)ld++;
        int ud = binarySearch(UB);
        if(pr[ud]>UB)ud--;

        vector<int>ans;
        bool suru=false;

        for(int i=ld; i<=ud; i++){
            if(start[pr[i]])suru = true;
            if(suru)ans.push_back(pr[i]);
            if(stop[pr[i]]){
                if(ans.size()>=3){
                    printf("%d",ans[0]);
                    for(int k=1; k<ans.size(); k++){
                        printf(" %d",ans[k]);
                    }
                    printf("\n");
                }
                suru = false;
                ans.clear();
                if(start[pr[i]])suru = true;
                if(suru)ans.push_back(pr[i]);
            }
        }
    }
    return 0;
}
