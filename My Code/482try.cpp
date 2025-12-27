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
    char ch;
    scanf("%d\n",&t);
    while(t--)
    {
        int sz=0;
        //scanf("%ld",&x);
        //int cnt=0;
        while(true)
        {
            scanf("%d",&x);
            arr[sz++].indx=x-1;

            if(getchar() == '\n')
                break;
        }


        //long int sz = n.size();
        //printf("%d\n",sz);

        //string s;

        for(int i=0; i<sz; i++){
            //scanf("%s",v[i]);
            cin >> arr[i].val;
        }

        sort(arr,arr+sz,cmp);

        if(flag){
            printf("\n");
        }
        flag=1;

        for(int i=0; i<sz; i++)
        {
            cout << arr[i].val << endl;
        }

        //v.clear();
        //n.clear();

    }

    return 0;
}
