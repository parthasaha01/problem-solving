#include<bits/stdc++.h>
using namespace std;
string m;
int a[15],s;
bool alldivisible()
{
    int sz = m.size();
    for(int k=0; k<s; k++)
    {
        int num=0;
        int rem;

        for(int i=0; i<sz; i++)
        {
            num += m[i]-'0';
            rem = num%a[k];
            num = rem*10;
        }

        if(rem!=0){
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        cin >> m;

        scanf("%d",&s);

        for(int i=0; i<s; i++){
            scanf("%d",&a[i]);
        }

        bool flag = alldivisible();

        if(flag){
            cout<<m<<" - Wonderful."<<endl;
        }
        else{
            cout<<m<<" - Simple."<<endl;
        }

    }

    return 0;
}
