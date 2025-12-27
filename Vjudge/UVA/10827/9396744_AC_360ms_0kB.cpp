#include<algorithm>
#include<cstdio>
 
using namespace std;
 
int T, N;
int A[500][500];
 
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 0; i < N * 2; i++) {
            for(int j = 0; j < N * 2; j++) {
                if(i < N && j < N) {
                    scanf("%d", &A[i][j]);
                    A[i + N][j] = A[i][j + N] = \
                        A[i + N][j + N] = A[i][j];
                }
                if(i > 0) A[i][j] += A[i - 1][j];
                if(j > 0) A[i][j] += A[i][j - 1];
                if(i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        int ans = -1000000;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = i; k < i + N; k++) {
                    for(int l = j; l < j + N; l++) {
                        int cur = A[k][l];
                        if(i > 0) cur -= A[i - 1][l];
                        if(j > 0) cur -= A[k][j - 1];
                        if(i > 0 && j > 0)
                            cur += A[i - 1][j - 1];
                        ans = max(ans, cur);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}