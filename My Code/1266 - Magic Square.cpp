#include<bits/stdc++.h>
using namespace std;
int MagicSquare[20][20];
void OddMagicSquare(int RB, int CB, int HN, int FV, int LV)
{
    memset(MagicSquare,0,sizeof(MagicSquare));
    int row,col,num;
    row=RB;
    col=HN/2+CB;

    for(num=FV; num<=LV; )
    {
        if(MagicSquare[row][col]!=0)    // this position already contains a number
        {
            row=row+2;
            col=col-1;

            if(row>HN+RB-1)
                row = row-HN;
            if(col<CB)
                col = HN+CB-1;
            continue;
        }
        else
        {
            MagicSquare[row][col]=num;
            num++;

            row--;
            col++;

            if(row<RB)
                row=HN+RB-1;
            if(col>HN+CB-1)
                col=CB;
        }
    }
}
void PrintMagicSquare(int n)
{
    int row,col;

    if(n==3)
    {
        for(row=0; row<n; row++)
        {
            for(col=0; col<n; col++)
            {
                printf(" %d",MagicSquare[row][col]);
                //else printf("%d ",MagicSquare[row][col]);
            }
            printf("\n");
        }
    }
    else if(n<=9)
    {
        for(row=0; row<n; row++)
        {
            for(col=0; col<n; col++)
            {
                printf(" %2d",MagicSquare[row][col]);
                //else printf("%2d ",MagicSquare[row][col]);
            }
            printf("\n");
        }
    }
    else
    {
        for(row=0; row<n; row++)
        {
            for(col=0; col<n; col++)
            {
                printf(" %3d",MagicSquare[row][col]);
                //else printf("%3d ",MagicSquare[row][col]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int ks=0,n;
    while(scanf("%d",&n)==1)
    {
        if(ks)printf("\n");
        ks=1;

        int sum = ((n*n*n)+n)/2;

        printf("n=%d, sum=%d\n",n,sum);

        OddMagicSquare(0, 0, n, 1, n*n);
        PrintMagicSquare(n);
    }
    return 0;
}
