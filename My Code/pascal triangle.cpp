#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll c[60][60];
int main()
{
    memset(c,0,sizeof(c));

    for(int i=1; i<55; i++)
    {
        for(int j=1; j<55; j++)
        {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
}
