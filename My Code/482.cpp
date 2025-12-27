#include<bits/stdc++.h>
using namespace std;
struct type
{
    int indx;
    string val;
}arr[10000];

bool cmp(type a, type b)
{
    return a.indx < b.indx;
}
int main()
{
    int x, t,flag=0;
    char s[100000];
    bool blank = false;
    scanf("%ld",&t);
    getchar();
    while(t--)
    {
        getchar();
        gets(s);

        char *pch = strtok(s, " ");
        int k=0;

        while(pch !=NULL)
        {
            x = atoi(pch);
            arr[k++].indx = x;
            pch = strtok(NULL, " ");
        }

        gets(s);

        pch = strtok(s, " ");
        k=0;

        while(pch !=NULL)
        {
            arr[k++].val = pch;
            pch = strtok(NULL, " ");
        }

        sort(arr,arr+k,cmp);

        if(blank)
            printf("\n");

        blank = true;

        for(int i=0; i<k; i++){
            cout << arr[i].val << endl;
        }

    }

    return 0;
}
