#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

//{{{ ************[  Floating points     ]************
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++)
    {
        int m, n;
        cin>>m>>n;
        int temp, mn = INF;

        for (int i = 2; i <= m; i++)
        {
            if (m % i == 0)
            {
                int cnt = 0;

                while (m % i == 0)
                {
                    m /= i;
                    cnt++;
                }

                temp = n;
                int total = 0;

                while (temp /= i)
                {
                    total += temp;
                }

                mn = min (mn, total / cnt);
            }
        }

        printf ("Case %d:\n",kase);

        if (!mn)
            cout<<"Impossible to divide"<<endl;
        else
            cout<<mn<<endl;
    }

    return 0;
}
