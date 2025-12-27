#include<bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
int grid[9][9];
int n,N;
bool SolveSudoku();
bool FindUnassignedLocation(int &row, int &col);
bool isSafe(int row, int col, int num);
bool UsedInRow(int row, int num);
bool UsedInCol(int col, int num);
bool UsedInBox(int boxStartRow, int boxStartCol, int num);
void printGrid();

bool SolveSudoku()
{
    int row,col;

    if(FindUnassignedLocation(row,col)==false)
        return true;

    for(int num=1; num<=N; num++)
    {
        if(isSafe(row,col,num))
        {
            grid[row][col]=num;

            if(SolveSudoku())
                return true;
            grid[row][col]=UNASSIGNED;
        }
    }
    return false;
}
bool FindUnassignedLocation(int &row, int &col)
{
    for(row=0; row<N; row++){
        for(col=0; col<N; col++){
            if(grid[row][col]==UNASSIGNED)
                return true;
        }
    }
    return false;
}
bool isSafe(int row, int col, int num)
{
    return !UsedInRow(row,num) &&
           !UsedInCol(col,num) &&
           !UsedInBox(row-row%n,col-col%n,num);
}
bool UsedInRow(int row, int num)
{
    for(int col=0; col<N; col++){
        if(grid[row][col]==num)
            return true;
    }
    return false;
}
bool UsedInCol(int col, int num)
{
    for(int row=0; row<N; row++){
        if(grid[row][col]==num)
            return true;
    }
    return false;
}
bool UsedInBox(int boxStartRow, int boxStartCol, int num)
{
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(grid[row+boxStartRow][col+boxStartCol]==num)
                return true;
        }
    }
    return false;
}
void printGrid()
{
    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N; col++)
        {
            if(col==0)
                cout << grid[row][col];
            else
                cout << " " << grid[row][col];
        }
        cout << endl;
    }
}
int main()
{
    int i=0;

    while(cin >> n)
    {
        N=n*n;
        for(int row=0; row<N; row++){
            for(int col=0; col<N; col++){
                cin >> grid[row][col];
            }
        }

        if(i)
            cout << endl;
        i=1;

        if(SolveSudoku()==true)
            printGrid();
        else
            cout << "NO SOLUTION" << endl;
    }

    return 0;
}
