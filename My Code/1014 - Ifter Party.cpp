#include<bits/stdc++.h>
using namespace std;
set<int>st;
void divisor(int n, int l){
    st.clear();
    int sq=sqrt(n);
    for(int i=1; i<=sq; i++){
        if(n%i==0){
            if(i>l) st.insert(i);
            if(n/i>l) st.insert(n/i);
        }
    }
}
int main(){
    int t; scanf("%d",&t);
    for(int ks=1; ks<=t; ks++){
        int p,l; scanf("%d%d",&p,&l);
        if(l>p) swap(l,p);
        int n=p-l;

        divisor(n,l);

        int sz=st.size();
        if(sz==0){
            printf("Case %d: impossible\n",ks);
        }
        else{
            set<int>::iterator it;
            printf("Case %d:",ks);
            for(it=st.begin(); it!=st.end(); it++){
                printf(" %d",*it);
            }
            printf("\n");
        }
    }
    return 0;
}
