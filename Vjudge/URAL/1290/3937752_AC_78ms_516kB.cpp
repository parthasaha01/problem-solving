#include<bits/stdc++.h>
using namespace std;
#define mx 25005
int p[mx];
int main()
{
    int N;

    cin >> N;

    for(int i=0; i<N; i++)
    {
        scanf("%d",&p[i]);
    }
    sort(p,p+N);
    for(int i=N-1; i>=0; i--)
    {
        printf("%d\n",p[i]);
    }

    return 0;
}
