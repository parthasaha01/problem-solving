#include<bits/stdc++.h>
#include <bitset>
using namespace std;
#define Inf 100000
long A[105],B[105];

int main()
{
    long T,m,n,i,j,Min,num,cnt;
    int Xor;

    cin >> T;

    while(T--)
    {
        cin >> m >> n;

        for(i=0; i<m; i++)
            cin >> A[i];
        for(i=0; i<n; i++)
            cin >> B[i];

        sort(A,A+m);

        for(i=0; i<n; i++)
        {
            Min=Inf;
            for(j=0; j<m; j++)
            {
                Xor=(B[i]^A[j]);
                cnt=__builtin_popcount(Xor);
                if(cnt<Min)
                {
                    Min=cnt;
                    num=A[j];
                }
            }
            cout << num << endl;
        }
    }

    return 0;
}
