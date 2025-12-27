#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x0,x1, y0, y1,cx, cy, r;

    int test, l, w, l1, l2;

    cin >> test;

    while(test--)
    {
        cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;

        l = x1 - x0;
        w = y1 - y0;

        l1 = cx - x0;
        l2  = cy - y0;

        if((l1 * 20 == l * 9) && (l2 * 2 == w) && (10 * w == 6 * l) && (r * 6 == w * 2)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
