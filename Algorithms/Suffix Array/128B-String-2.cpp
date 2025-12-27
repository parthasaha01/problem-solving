#include<bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int suffixarank[20][MAX + 10];

struct myTuple{
    int firstHalf;
    int secondHalf;
    int originalIndex;
};

string str;

myTuple L[MAX + 10];
int lcp[MAX + 10];
int t, cs = 1, m, n, k;
int globalstp;

// rnk[i] means value of ith suffix in the sorted suffix array
// A[i] means position of the ith suffix in the sorted suffix array
int A[MAX + 10], rnk[MAX + 10];


bool cmp(const myTuple &A, const myTuple &B)
{
    if(A.firstHalf == B.firstHalf) return A.secondHalf < B.secondHalf;
    return A.firstHalf < B.firstHalf;

}

void getSA(string str)
{

    int len = str.size();
    memset(suffixarank, 0, sizeof(suffixarank));
    memset(rnk , 0 , sizeof(rnk));
    memset(A, 0, sizeof(A));
    memset(lcp, 0, sizeof(lcp));


    for(int i = 0 ; i < len; i++) suffixarank[0][i] = str[i] - 'A';

    int stp = 1, cnt = 1;

    for(stp = 1, cnt = 1; cnt <= len; cnt = cnt * 2, stp++){

        for(int i = 0; i < len; i++){
            L[i].firstHalf = suffixarank[stp - 1][i];
            L[i].secondHalf = ((i + cnt) < len) ? suffixarank[stp - 1][i + cnt] : -1;
            L[i].originalIndex = i;
        }

        sort(L, L + len, cmp);

        suffixarank[stp][L[0].originalIndex] = 0;
        int currRank = 0;

        for(int i = 1; i < len; i++){

            if(L[i].firstHalf != L[i - 1].firstHalf || L[i].secondHalf != L[i - 1].secondHalf) currRank++;

            suffixarank[stp][L[i].originalIndex] = currRank;

        }

    }

    globalstp = stp;

    for(int i = 0; i < len; i++) A[i] = suffixarank[stp - 1][i];
    for(int i = 0; i < len; i++) rnk[A[i]] = i;
}

int LCP(int x, int y)
{
    int len = str.size();
    int k, re = 0;
    if (x == y) return len - x;

    for (k = globalstp - 1; k >= 0 && x < len && y < len; k --){
        if (suffixarank[k][x] == suffixarank[k][y]){
            x += 1 << k, y += 1 << k, re += 1 << k;
        }
    }
    return re;
}

void getLCP(string str)
{
    int len = str.size();
    for(int i = 1; i < len; i++){
        lcp[i] = LCP(rnk[i], rnk[i - 1]);
    }

}
int main()
{
    cin >> str >> k;

    getSA(str);
    getLCP(str);

    int len = str.size();

    for(int i = 0; i < len; i++){

        int lenfromhere = len - rnk[i];

        int cmn = lcp[i];

//        cout << i << ' ' << rnk[i] << ' ' << cmn << ' ' << k << endl;

        for(int j = cmn + 1; j <= lenfromhere; j++){
            k--;
            for(int l = i + 1; l < len; l++){
                if(k == 0) break;
                if(lcp[l] >= j){
                    k--;
                }
                else break;
            }

            if(k == 0){

                for(int l = rnk[i], m = 0; m < j; l++, m++) printf("%c", str[l]);
                return 0;
            }

        }

    }

    printf("No such line.\n");

    return 0;
}

