#include<bits/stdc++.h>
using namespace std;
string a,b;
long int arr[200002];
int main()
{
    long long int res=0;
    long int len1,len2,i,j,endd,beg,sum,diff;

    cin>>a>>b;

    len1=a.size();
    len2=b.size();
    arr[1]=b[0]-48;
    for(i=1; i<len2; i++)
    {
        arr[i+1]=arr[i]+(b[i]-48);
    }

    diff=len2-len1+1;
    endd=diff;
    beg=0;
    for(i=0; i<len1; i++)
    {
        sum=arr[endd]-arr[beg];
        if(a[i]=='0'){
            res+=sum;
        }
        else
        {
            res+=(diff-sum);
        }
        endd++;
        beg++;
    }

    cout << res << endl;

    return 0;
}
