#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[50],b[50];
int main()
{
    int t;
    cin >> t;

    ll res,n,cnt1,cnt2,len,len2,k,n1,get0,get1,rem,flag,diff;

    for(int kase=1; kase<=t; kase++)
    {
        cin >> n;
        n1=n;
        cnt1=0;
        k=0;
        while(n1!=0)
        {
            rem=n1%2;
            a[k++]=rem;
            if(rem==1){
                ++cnt1;
            }
            n1=n1/2;
        }

        len=k;

        for(int i=0; i<len; i++)
        {
            if(a[i]==1){
                get1=i;
                break;
            }
        }
        flag=0;
        for(int i=get1+1; i<len; i++)
        {
            if(a[i]==0)
            {
                get0=i;
                a[i]=1;
                flag=1;
                break;
            }
        }

        if(flag)
        {
            //k=len-1;
            cnt2=0;
            for(int i=len-1; i>=get0; i--)
            {
                b[i] = a[i];
                if(a[i]==1){
                    cnt2++;
                }

            }
            diff=cnt1-cnt2;
            for(int i=0; i<diff; i++){
                b[i]=1;
            }
            for(int i=diff; i<get0; i++){
                b[i]=0;
            }
            len2=len;
        }
        else
        {
            b[len]=1;
            cnt2=1;
            diff=cnt1-cnt2;

            for(int i=0; i<diff;  i++){
                b[i]=1;
            }
            for(int i=diff; i<len; i++){
                b[i]=0;
            }
            len2=len+1;
        }

        res=0;

        for(int i=0; i<len2; i++){
            if(b[i]==1){
                res += pow(2,i);
            }
        }

        cout << "Case " << kase << ": " << res << endl;
    }

    return 0;
}
