#include<bits/stdc++.h>
using namespace std;
int k,a[200005];
string s;
int fun(int k,int id)
{
    int cnt = a[k];
    int sum = (cnt*(cnt+1))/2;

    for(int i=0; i<=cnt; i++){
        s+='a'+id;
    }
    int kk = k-sum;
    return kk;
}
int main()
{
    int sum=0;
    int p=0;
    while(sum<=100003)
    {
        p++;
        sum+=p;
        a[sum]=p;
    }
    for(int i=1; i<=100003; i++)
    {
        if(a[i]==0){
            a[i]=a[i-1];
        }
    }

//    for(int i=1; i<=100; i++)
//    {
//        printf("%d %d\n",i,a[i]);
//    }

    scanf("%d",&k);

    if(k==0)
    {
        printf("ab\n");
        return 0;
    }
    if(k==1)
    {
        printf("aa\n");
        return 0;
    }

    int id=0;

    while(k>0)
    {
        k = fun(k,id);
        id++;
    }

    cout << s << endl;

    return 0;
}
