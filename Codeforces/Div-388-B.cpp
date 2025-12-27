#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    printf("3\n");

    x4 = (x2+x3)-x1;
    y4 = (y2+y3)-y1;
    printf("%d %d\n",x4,y4);

    x4 = (x1+x3)-x2;
    y4 = (y1+y3)-y2;
    printf("%d %d\n",x4,y4);

    x4 = (x1+x2)-x3;
    y4 = (y1+y2)-y3;
    printf("%d %d\n",x4,y4);

    return 0;
}
