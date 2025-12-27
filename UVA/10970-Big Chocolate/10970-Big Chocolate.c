#include<stdio.h>
int main()
{
    int row, column, result;

    while(scanf("%d %d", &row, &column) != EOF)
    {
        result = (row*column)-1;
        printf("%d\n", result);
    }

    return 0;
}
