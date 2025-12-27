#include<bits/stdc++.h>
using namespace std;
int gp[10001][5001], dp[10001][501][2];
int d,s,ase;
int Generate(int pos,int sum){
    if(sum<0)return 0;
    if(pos==31){
        if(sum==0)return 1;
        return 0;
    }

    int &ret = gp[pos][sum];
    if(ret!=-1)return ret;
    ret = 0;
    for(int i=0; i<=9; i++){
        ret |= Generate(pos+1,sum-i);
    }
    return ret;
}
int fun(int pos,int rem,int suru,int sum){
    if(ase==1)return 1;
    if(pos==31){
        if(suru==1 && rem==0 && sum==0){
            ase = 1;
            return 1;
        }
        return 0;
    }

    int &ret = dp[pos][rem][suru];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=0; i<=9; i++){
        int f = Generate(pos+1,sum-i);
        if(f==1){
            ret |= fun(pos+1,((rem*10)+i)%d, suru | i>0, sum-i);
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&d,&s);
    memset(gp,-1,sizeof(gp));
    memset(dp,-1,sizeof(dp));
    ase=0;
    int gg = Generate(1,s-1);
    int flag = fun(0,0,0,s);
    printf("ase=%d\n",ase);
    if(flag==0){
        printf("-1\n");
    }else{

    }
    return 0;
}
//10000 00000 00000 00000 00000 00000 1
