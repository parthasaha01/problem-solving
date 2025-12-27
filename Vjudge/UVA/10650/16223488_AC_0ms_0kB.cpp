#include<stdio.h>
#include<math.h>
#define N 32100
struct data{
    int Beg, End;
}st[205];
int isprime[N+5],pr[3450],sz=0,k=0;
void sieve(){
    for(int i=2; i<=32100; i++) isprime[i] = 1;
    for(int i=2; i<=32100; i++){
        if(isprime[i]==1){
            pr[++sz] = i;
            for(int j=i+i; j<=32100; j+=i){
                isprime[j] = 0;
            }
        }
    }
}
void precalc(){
    k = 0;
    for(int i=1; i<sz-1; ){
        int d = pr[i+1] - pr[i];
        int cnt = 2;
        int j = i+1;
        while(j+1<=sz && pr[j+1]-pr[j]==d){
            j++;
            cnt++;
        }
        if(cnt>2){
            ++k;
            st[k].Beg = i;
            st[k].End = j;
        }
        i = j;
    }

}
void solve(int x,int y){
    if(x>y){
        int temp = x;
        x = y;
        y = temp;
    }
    for(int i=1; i<=k; i++){
        if(pr[st[i].Beg]>=x && pr[st[i].End]<=y){
            for(int j=st[i].Beg; j<=st[i].End; j++){
                if(j==st[i].End)printf("%d\n",pr[j]);
                else printf("%d ",pr[j]);
            }
        }
    }
}
int main(){
    sieve();
    precalc();

    int x,y;
    while(scanf("%d%d",&x,&y)){
        if(x==0 && y==0)break;
        solve(x,y);
    }
    return 0;
}