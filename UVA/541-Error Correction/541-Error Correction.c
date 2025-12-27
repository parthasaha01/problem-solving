#include<stdio.h>
int parity(int N);
int Rn, Cn;
int main()
{
    int N, result;

    while(scanf("%d", &N)==1 && N!=0)
    {
        result = parity(N);

        if(result == 0)
            printf("OK\n");
        else if(result == 1)
            printf("Change bit (%d,%d)\n", Rn+1, Cn+1);
        else
            printf("Corrupt\n");
    }

    return 0;
}
int parity(int N)
{
    int mat[N][N];
    int x, y, row, col, r, c;

    r=c=0;

    for(x=0; x<N; x++)
    {
        for(y=0; y<N; y++)
        {
            scanf("%d", &mat[x][y]);
        }
    }

    for(x=0; x<N; x++)
    {
        row=col=0;
        for(y=0; y<N; y++)
        {
            row += mat[x][y];
            col += mat[y][x];
        }

        if((row%2) != 0)
        {
            r++;
            Rn=x;
        }
        if((col%2) != 0)
        {
            c++;
            Cn=x;
        }
    }

    if(r<1 && c<1)
        return 0;
    else if(r > 1 || c>1)
        return 2;
    else
    {

        if(mat[Rn][Cn] == 0)
            mat[Rn][Cn] = 1;
        else
            mat[Rn][Cn] = 0;

            row=col=0;

        for(y=0; y<N; y++)
            row += mat[Rn][y];

        if((row%2) == 0)
        {
            for(x=0; x<N; x++)
                col += mat[x][Cn];

            if((col%2) == 0)
                return 1;
            else
                return 2;
        }

    }
}
