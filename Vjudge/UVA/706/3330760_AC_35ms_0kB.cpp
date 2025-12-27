#include<bits/stdc++.h>
using namespace std;
int main()
{
    char n[10];
    int s,l,i,j,r,c,d1,d2,m1,m2,space,col,row,Tcol,pos;

    while(scanf("%d %s",&s,n)==2)
    {
        if((s==0) && (!strcmp("0",n)))
            break;

        l = strlen(n);

        col = s+2;
        row = (2*s)+3;
        Tcol = ((s+2)*l);

        int a[row][Tcol];

        for(i=0;i<row;i++)
        {
            for(j=0;j<Tcol;j++)
            {
                a[i][j]=0;
            }
        }

        for(i=0; i<l; i++)
        {
            pos = i+1;
            switch(n[i])
            {
                case '1':
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d2] = 1;  // "|"
                        a[r+s+2][d2] = 1;
                    }
                    break;
                case '2':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d2] = 1;  // "|"
                        a[r+s+2][d1] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[0][m1+c] = 2;
                        a[s+1][m1+c] = 2;
                        a[row-1][m1+c] = 2;
                    }
                    break;
                case '3':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d2] = 1;  // "|"
                        a[r+s+2][d2] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[0][m1+c] = 2;
                        a[s+1][m1+c] = 2;
                        a[row-1][m1+c] = 2;
                    }
                    break;
                case '4':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d1] = 1;  // "|"
                        a[r+1][d2] = 1;  // "|"
                        a[r+s+2][d2] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[s+1][m1+c] = 2;
                    }
                    break;
                case '5':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d1] = 1;  // "|"
                        a[r+s+2][d2] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[0][m1+c] = 2;
                        a[s+1][m1+c] = 2;
                        a[row-1][m1+c] = 2;
                    }
                    break;
                case '6':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d1] = 1;  // "|"
                        a[r+s+2][d1] = 1;
                        a[r+s+2][d2] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[0][m1+c] = 2;
                        a[s+1][m1+c] = 2;
                        a[row-1][m1+c] = 2;
                    }
                    break;
                case '7':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d2] = 1;  // "|"
                        a[r+s+2][d2] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[0][m1+c] = 2;
                    }
                    break;
                case '8':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d1] = 1;  // "|"
                        a[r+1][d2] = 1;  // "|"
                        a[r+s+2][d1] = 1;
                        a[r+s+2][d2] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[0][m1+c] = 2;
                        a[s+1][m1+c] = 2;
                        a[row-1][m1+c] = 2;
                    }
                    break;
                case '9':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d1] = 1;  // "|"
                        a[r+1][d2] = 1;  // "|"
                        a[r+s+2][d2] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[0][m1+c] = 2;
                        a[s+1][m1+c] = 2;
                        a[row-1][m1+c] = 2;
                    }
                    break;
                case '0':
                    d1 = (pos-1)*col;    //col = s+2
                    d2 = (pos*col)-1;
                    for(r=0;r<s;r++)
                    {
                        a[r+1][d1] = 1;  // "|"
                        a[r+1][d2] = 1;  // "|"
                        a[r+s+2][d1] = 1;
                        a[r+s+2][d2] = 1;
                    }
                    m1=d1+1;
                    for(c=0;c<s;c++)
                    {
                        a[0][m1+c] = 2;
                        a[row-1][m1+c] = 2;
                    }
                    break;

            }
        }

        for(i=0;i<row;i++)
        {
            space = 1;
            for(j=0;j<Tcol;j++)
            {
                if(a[i][j] == 1)
                {
                    printf("|");
                }
                else if(a[i][j] == 2)
                {
                    printf("-");
                }
                else
                {
                    printf(" ");
                }

                space++;
                if(space>col)
                {
                    if(j<Tcol-1)
                        printf(" ");

                    space = 1;
                }
            }
            printf("\n");
        }

        printf("\n");

    }

    return 0;

}
