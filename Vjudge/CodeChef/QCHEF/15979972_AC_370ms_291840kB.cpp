#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
const int MAXV = 1e5+5;
const int SQRN = 350;
int N, M, Q, BLOCKN, BLOCK_SIZE, a[MAXN];
int Prev[MAXN], Next[MAXN], last[MAXV], Index[MAXV], found[MAXV];
int last_in_blocks[SQRN][MAXN], block_ans[SQRN][MAXN];

void Debug(){

    printf("Previous array:\n");
    for(int i=1; i<=N; i++){
        printf("%d ",Prev[i]);
    }
    printf("\n\n");

    printf("Next array:\n");
    for(int i=1; i<=N; i++){
        printf("%d ",Next[i]);
    }
    printf("\n\n");

    printf("last_in_blocks:\n");
    for(int b=1; b<=BLOCKN; b++){
        printf("Block %d:\n",b);
        for(int i=1; i<=N; i++){
            printf("%d ",last_in_blocks[b][i]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("block_ans:\n");
    for(int b=1; b<=BLOCKN; b++){
        printf("Block %d:\n",b);
        for(int i=1; i<=N; i++){
            printf("%d ",block_ans[b][i]);
        }
        printf("\n");
    }
    printf("\n\n");

}
void preprocess(){

    BLOCK_SIZE = floor(sqrt(N));
    BLOCKN = ceil(N/BLOCK_SIZE);

    for(int i=1; i<=M; i++) last[i] = 0;
    for(int i=1; i<=N; i++) Prev[i] = 0;
    for(int i=1; i<=N; i++) Next[i] = N+1;

    for(int i=1; i<=N; i++){
        if(last[a[i]] != 0){
            Next[last[a[i]]] = i;
            Prev[i] = last[a[i]];
        }
        last[a[i]] = i;
    }

    memset(last_in_blocks, 0, sizeof(last_in_blocks));
    for(int b=1; b<=BLOCKN; b++){
        int LB = (b*BLOCK_SIZE) - BLOCK_SIZE + 1;
        int RB = min(b*BLOCK_SIZE, N);
        for(int y=LB; y<=RB; y++){
            if(Next[y]>RB){
                int x = y;
                while(x>0){
                    last_in_blocks[b][x] = y;
                    x = Prev[x];
                }
            }
        }
    }
    for(int x=1; x<=N; x++){
        for(int b=2; b<=BLOCKN; b++){
            if(last_in_blocks[b][x]==0){
                last_in_blocks[b][x] = last_in_blocks[b-1][x];
            }
        }
    }

    int mytime = 0;
    memset(found,0,sizeof(found));
    memset(Index,0,sizeof(Index));
    for(int b=1; b<=BLOCKN; b++){
        mytime++;
        int ans = 0;
        int LB = (b*BLOCK_SIZE) - BLOCK_SIZE + 1;
        for(int y=LB; y<=N; y++){
            if(found[a[y]]!=mytime){
                Index[a[y]] = y;
                found[a[y]] = mytime;
            }
            ans = max(ans, y-Index[a[y]]);
            block_ans[b][y] = ans;
        }
    }

    //Debug();
}
int queryInBlock(int L,int R){
    map<int,int>MP;
    int ans = 0;
    for(int x=L; x<=R; x++){
        if(MP.find(a[x])==MP.end()){
            MP[a[x]] = x;
        }
        ans = max(ans, x-MP[a[x]]);
    }
    return ans;
}
int solve(int L, int R){
    int Lblock = (L+BLOCK_SIZE-1) / BLOCK_SIZE;
    int Rblock = R / BLOCK_SIZE;
    //cout << "LBlock="<< Lblock << " " << "RBlock="<< Rblock << endl;
    int ans = 0;
    if(Lblock>=Rblock){
        ans = queryInBlock(L,R);
    }
    else{
        int LblockEnd = Lblock*BLOCK_SIZE;
        ans = block_ans[Lblock+1][R];
        //cout << "LBlockEnd="<< LblockEnd << " " << "ans="<< ans << endl;
        for(int x=L; x<=LblockEnd; x++){
            if(Prev[x]<L){
                int y = last_in_blocks[(int)floor(R/BLOCK_SIZE)][x];
                while(Next[y]<=R){
                    y = Next[y];
                }
                ans = max(ans, y-x);
                //printf("x=%d ans=%d\n",x,ans);
            }
        }
    }
    return ans;
}
int main(){

    scanf("%d%d%d",&N,&M,&Q);
    for(int i=1; i<=N; i++){
        scanf("%d",&a[i]);
    }

    preprocess();

    for(int i=1; i<=Q; i++){
        int L,R; scanf("%d%d",&L,&R);
        if(L>R)swap(L,R);
        int ans = solve(L,R);
        printf("%d\n",ans);
    }
    return 0;
}
