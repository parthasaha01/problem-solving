#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);

    int d = (x*x)+(y*y);

    int sd = sqrt(d);

    if(d==(sd*sd))
    {
        printf("black\n");
        return 0;
    }

    if(x>=0 && y>=0)
    {
        x = abs(x);
        y = abs(y);

        if(sd%2==0)printf("black\n");
        else printf("white\n");
    }
    else if(x<0 && y>=0)
    {
        x = abs(x);
        y = abs(y);

        if(sd%2==1)printf("black\n");
        else printf("white\n");
    }
    else if(x<0 && y<0)
    {
        x = abs(x);
        y = abs(y);

        if(sd%2==0)printf("black\n");
        else printf("white\n");
    }
    else    // x>=0 && y<0
    {
        x = abs(x);
        y = abs(y);

        if(sd%2==1)printf("black\n");
        else printf("white\n");

    }

    //main();
    return 0;
}
